#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include "Course.h"
#include "Student.h"
#include <vector>
#include <string>
#include <unordered_map>

class Course;

class Professor : public Person {
private:
    std::string department;
    std::vector<std::string> courses;
    std::unordered_map<std::string, int> courseSemesters;

public:
    // Constructors
    Professor();
    Professor(const std::string &name, int age, const std::string &employeeID,
              const std::string &department, const std::vector<std::string> &courses);

    // Destructor
    ~Professor();

    // Accessors
    std::string getDepartment() const;
    std::vector<std::string> getCourses() const;

    // Mutators
    void setDepartment(const std::string &department);
    void setCourses(const std::vector<std::string> &courses);

    // Overriding the << operator for convenient output
    friend std::ostream &operator<<(std::ostream &out, const Professor &professor);

    void assignCourseForSemester(const std::string& courseName, int semester);

    void modifyProfessor(const std::string& newName, int newAge, const std::string& newDepartment);
    

};

#endif // PROFESSOR_H
