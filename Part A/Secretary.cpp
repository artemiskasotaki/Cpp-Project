#include "Secretary.h"

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

        for (const Person *person : other.departmentMembers) {
            departmentMembers.push_back(new Person(*person));
        }
    }
    return *this;
}
