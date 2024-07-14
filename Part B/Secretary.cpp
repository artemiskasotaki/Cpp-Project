#include "Secretary.h"
#include "Professor.h"
#include "Course.h"
#include "Student.h"
#include "Person.h"
#include <unordered_map>
#include <algorithm>
#include <fstream>

Secretary::Secretary() = default;

Secretary::~Secretary() {
    for (Person *person : departmentMembers) {
        delete person;
    }
    departmentMembers.clear();
}

void Secretary::operator+=(Person *person) {
    departmentMembers.push_back(person);
}

std::ostream &operator<<(std::ostream &out, const Secretary &secretary) {
    for (const Person *person : secretary.departmentMembers) {
        out << *person << "\n";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Secretary &secretary) {
    Person *newPerson = new Person();
    in >> *newPerson;
    secretary += newPerson;
    return in;
}

bool Secretary::findPerson(const std::string &name) const {
    for (const Person *person : departmentMembers) {
        if (person->getName() == name) {
            return true;
        }
    }
    return false;
}

Secretary::Secretary(const Secretary &other) {
    for (const Person *person : other.departmentMembers) {
        departmentMembers.push_back(new Person(*person));
    }
}

Secretary &Secretary::operator=(const Secretary &other) {
    if (this != &other) {
        for (Person *person : departmentMembers) {
            delete person;
        }
        departmentMembers.clear();

        // Δημιουργία νέων αντικειμένων
        for (const Person *person : other.departmentMembers) {
            departmentMembers.push_back(new Person(*person));
        }
    }
    return *this;
}

void Secretary::assignProfessorToCourse(const std::string& courseName, Professor* professor, int semester) {
    for (Person* person : departmentMembers) {
        if (person->getRole() == "Professor") {
            Professor* currentProfessor = dynamic_cast<Professor*>(person);
            if (currentProfessor) {
                for (const std::string& course : currentProfessor->getCourses()) {
                    if (course == courseName) {
                        currentProfessor->assignCourseForSemester(courseName, semester);
                        return;
                    }
                }
            }
        }
    }
    throw std::runtime_error("Course or professor not found.");
}

const std::vector<Person*>& Secretary::getDepartmentMembers() const {
    return departmentMembers;
}

void Secretary::addCourse(const Course& course) {
    for (Course* existingCourse : courses) {
        if (existingCourse->getName() == course.getName()) {
            throw std::runtime_error("Course already exists. Use update option instead.");
        }
    }

    courses.push_back(new Course(course));

    // Προσθήκη των καθηγητών στο μάθημα
    Course* addedCourse = courses.back();
    for (const Professor* professor : course.getProfessors()) {
        addedCourse->addProfessor(professor);
    }
}


void Secretary::updateCourse(const Course& course) {
    for (Course* existingCourse : courses) {
        if (existingCourse->getName() == course.getName()) {
            *existingCourse = course;
            return;
        }
    }
    throw std::runtime_error("Course not found. Use add option instead.");
}

void Secretary::saveStudentsToFile(const std::vector<Student*>& students, const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile) {
        throw std::runtime_error("Could not open file for writing.");
    }

    for (const Student* student : students) {
        outFile << *student << "\n";
    }

    outFile.close();
}
