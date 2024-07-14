#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include <iostream>
#include <vector>
#include <unordered_map>


// Default Constructor
Student::Student()
    : currentSemester(1), professor(""), totalCredits(0.0) {}

// Parameterized Constructor
Student::Student(const std::string &name, int age, const std::string &studentID, float grade,
                 int semester, const std::string &professor)
    : Person(name, age, "Student", studentID, grade), currentSemester(semester), professor(professor), totalCredits(0.0) {}

// Destructor
Student::~Student() {

}

// Accessors
int Student::getSemester() const {
    return currentSemester;
}

std::string Student::getProfessor() const {
    return professor;
}

const std::vector<std::string>& Student::getEnrolledCourses() const {
    return enrolledCourses;
}

float Student::getTotalCredits() const {
    return totalCredits;
}

// Mutators
void Student::setSemester(int semester) {
    this->currentSemester = semester;
}

void Student::setProfessor(const std::string &professor) {
    this->professor = professor;
}

void Student::enrollInCourse(const Course& course) {
    try {
        if (course.isAvailableForEnrollment(currentSemester)) {
            enrolledCourses.push_back(course.getName());
            totalCredits += course.getTeachingUnits(); // Προσθήκη διδακτικών μονάδων
        } else {
            throw std::runtime_error("Course not available for enrollment in the current semester.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Student::enterGradeForCourse(const std::string& courseName, float grade) {
    for (size_t i = 0; i < enrolledCourses.size(); ++i) {
        if (enrolledCourses[i] == courseName) {
            std::cout << "Grade entered for course " << courseName << ": " << grade << std::endl;
            enrolledCourses.erase(enrolledCourses.begin() + i);
            break;
        }
    }
}

void Student::enrollInCourseForCurrentSemester(const std::string& courseName) {
    // Ελέγχουμε αν το μάθημα είναι διαθέσιμο για εγγραφή στο τρέχον ακαδημαϊκό εξάμηνο
    if (courseSemesters.find(courseName) != courseSemesters.end() && courseSemesters[courseName] == currentSemester) {
        enrolledCourses.push_back(courseName);
    } else {
        throw std::runtime_error("Course not available for enrollment in the current semester.");
    }
}

bool Student::graduate() {
    if (currentSemester == 8 && totalCredits >= 240) {
        std::cout << "Congratulations! " << getName() << " has graduated!" << std::endl;
        return true;
    } else {
        std::cout << getName() << " has not fulfilled the graduation requirements yet." << std::endl;
        return false;
    }
}

void Student::modifyStudent(const std::string& newName, int newAge) {
    setName(newName);
    setAge(newAge);
}


std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Name: " << student.getName() << ", Age: " << student.getAge() << ", StudentID: " << student.getStudentID() << ", Grade: " << student.getGrade();
    return out;
}
