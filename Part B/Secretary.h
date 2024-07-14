#ifndef SECRETARY_H
#define SECRETARY_H

#include "Person.h"
#include <vector>
#include "Professor.h"
#include "Course.h"
#include "Student.h"
#include <unordered_map>


class Secretary {
private:
    std::vector<Person *> departmentMembers;
    std::vector<Course *> courses;
public:
    Secretary();
    ~Secretary();

    void operator+=(Person *person);

    friend std::ostream &operator<<(std::ostream &out, const Secretary &secretary);
    friend std::istream &operator>>(std::istream &in, Secretary &secretary);

    bool findPerson(const std::string &name) const;

    Secretary(const Secretary &other);
    Secretary &operator=(const Secretary &other);
  
    void assignProfessorToCourse(const std::string& courseName, Professor* professor, int semester);

    const std::vector<Person *> &getDepartmentMembers() const;  // Προσθήκη const εδώ


    // Inside Secretary class definition
    void addCourse(const Course& course);
    void updateCourse(const Course& course);
 
    void saveStudentsToFile(const std::vector<Student*>& students, const std::string& filename) const;
    

};

#endif // SECRETARY_H

