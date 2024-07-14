// course.cpp
#include "Course.h"
#include <unordered_map>
#include <iostream>
using namespace std;

// Default Constructor
Course::Course()
    : semester(1), teachingUnits(0), mandatory(true) {}

// Parameterized Constructor
Course::Course(const std::string &name, int semester, int teachingUnits, bool mandatory)
    : name(name), semester(semester), teachingUnits(teachingUnits), mandatory(mandatory) {}

// Destructor
Course::~Course() {
    
}

// Accessors
std::string Course::getName() const {
    return name;
}

int Course::getSemester() const {
    return semester;
}

int Course::getTeachingUnits() const {
    return teachingUnits;
}

bool Course::isMandatory() const {
    return mandatory;
}

// Mutators
void Course::setName(const std::string &name) {
    this->name = name;
}

void Course::setSemester(int semester) {
    this->semester = semester;
}

void Course::setTeachingUnits(int teachingUnits) {
    this->teachingUnits = teachingUnits;
}

void Course::setMandatory(bool mandatory) {
    this->mandatory = mandatory;
}

// Function to move the course to a different semester
void Course::moveCourseToSemester(int newSemester) {
    if (newSemester > 0) {
        this->semester = newSemester;
    } else {
        cerr << "Invalid semester value." << endl;
    }
}

bool Course::isAvailableForEnrollment(int studentSemester) const {
    // Έλεγχος αν το μάθημα είναι διαθέσιμο για εγγραφή από το φοιτητή
    if (semester == studentSemester && mandatory) {
        // Εάν το μάθημα είναι υποχρεωτικό και ανήκει στο τρέχον ακαδημαϊκό εξάμηνο του φοιτητή
        return true;
    } else if (!mandatory && semester <= studentSemester) {
        // Εάν το μάθημα είναι επιλογής και είναι διαθέσιμο για εγγραφή από το φοιτητή
        return true;
    }
    return false;
}

void Course::inputCourse() {
    std::cout << "Enter course name: ";
    std::cin.ignore();  
    std::getline(std::cin, name);

    std::cout << "Enter semester: ";
    std::cin >> semester;

    std::cout << "Enter teaching units: ";
    std::cin >> teachingUnits;

    std::cout << "Is the course mandatory? (1 for yes, 0 for no): ";
    std::cin >> mandatory;
}

void Course::addProfessor(const Professor* professor) {
    professors.push_back(const_cast<Professor*>(professor));
}

void Course::assignProfessor(Professor* professor, int semester) {
    // Ελέγχουμε αν ο καθηγητής έχει ήδη ανατεθεί στο μάθημα
    for (const Professor* existingProfessor : professors) {
        if (existingProfessor == professor) {
            throw std::runtime_error("Professor already assigned to the course.");
        }
    }

    // Αναθέτουμε τον καθηγητή στο μάθημα για το συγκεκριμένο εξάμηνο
    professors.push_back(professor);
}

const std::vector<Professor*>& Course::getProfessors() const {
    return professors;
}
