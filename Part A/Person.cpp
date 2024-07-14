#include "Person.h"

int Person::count = 0;

Person::Person()
    : age(0), grade(0.0f) {
    ++count;
}

Person::Person(const std::string &name, int age, const std::string &role,
               const std::string &studentID, float grade)
    : name(name), age(age), role(role), studentID(studentID), grade(grade) {
    ++count;
}

Person::~Person() {
    --count;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

std::string Person::getRole() const {
    return role;
}

std::string Person::getStudentID() const {
    return studentID;
}

float Person::getGrade() const {
    return grade;
}

void Person::setName(const std::string &name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setRole(const std::string &role) {
    this->role = role;
}

void Person::setStudentID(const std::string &studentID) {
    this->studentID = studentID;
}

void Person::setGrade(float grade) {
    this->grade = grade;
}

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << "Name: " << person.name << ", Age: " << person.age << ", Role: " << person.role;
    if (person.role == "Student") {
        out << ", StudentID: " << person.studentID << ", Grade: " << person.grade;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Person &person) {
    std::cout << "Enter name: ";
    in >> person.name;
    std::cout << "Enter age: ";
    in >> person.age;
    std::cout << "Enter role (Student/Teacher): ";
    in >> person.role;

    if (person.role == "Student") {
        std::cout << "Enter student ID: ";
        in >> person.studentID;
        std::cout << "Enter grade: ";
        in >> person.grade;
    }

    return in;
}

int Person::getCount() {
    return count;
}
