#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    static int count;
    std::string name;
    int age;
    std::string role;
    std::string studentID;
    float grade;

public:
    Person();
    Person(const std::string &name, int age, const std::string &role,
           const std::string &studentID = "", float grade = 0.0f);

    ~Person();

    std::string getName() const;
    int getAge() const;
    std::string getRole() const;
    std::string getStudentID() const;
    float getGrade() const;

    void setName(const std::string &name);
    void setAge(int age);
    void setRole(const std::string &role);
    void setStudentID(const std::string &studentID);
    void setGrade(float grade);

    friend std::ostream &operator<<(std::ostream &out, const Person &person);
    friend std::istream &operator>>(std::istream &in, Person &person);

    static int getCount();
};

#endif // PERSON_H
