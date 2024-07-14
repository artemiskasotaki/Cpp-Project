#ifndef SECRETARY_H
#define SECRETARY_H

#include "Person.h"
#include <vector>

class Secretary {
private:
    std::vector<Person *> departmentMembers;

public:
    Secretary();
    ~Secretary();

    void operator+=(Person *person);

    friend std::ostream &operator<<(std::ostream &out, const Secretary &secretary);
    friend std::istream &operator>>(std::istream &in, Secretary &secretary);

    bool findPerson(const std::string &name) const;

    Secretary(const Secretary &other);
    Secretary &operator=(const Secretary &other);
};

#endif // SECRETARY_H
