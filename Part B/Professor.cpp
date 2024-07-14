#include "Professor.h"
#include "Course.h"
#include <unordered_map>

// Default Constructor
Professor::Professor()
    : department(""), courses({}), courseSemesters({}) {}

// Parameterized Constructor
Professor::Professor(const std::string &name, int age, const std::string &employeeID,
                     const std::string &department, const std::vector<std::string> &courses)
    : Person(name, age, "Professor", employeeID), department(department), courses(courses), courseSemesters({}) {}

// Destructor
Professor::~Professor() {
}

// Accessors
std::string Professor::getDepartment() const {
    return department;
}


std::vector<std::string> Professor::getCourses() const {
    return courses;
}

// Mutators
void Professor::setDepartment(const std::string &department) {
    this->department = department;
}

void Professor::setCourses(const std::vector<std::string> &courses) {
    this->courses = courses;
}

// Overriding the << operator for convenient output
std::ostream &operator<<(std::ostream &out, const Professor &professor) {
    out << static_cast<const Person &>(professor) << ", Department: " << professor.department
        << ", Courses: [";
    for (const std::string &course : professor.courses) {
        out << course << " ";
    }
    out << "]";
    return out;
}

void Professor::assignCourseForSemester(const std::string& courseName, int semester) {
    courseSemesters[courseName] = semester;
}


void Professor::modifyProfessor(const std::string& newName, int newAge, const std::string& newDepartment) {
    setName(newName);
    setAge(newAge);
}


