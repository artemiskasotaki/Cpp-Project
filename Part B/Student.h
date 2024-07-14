#ifndef STUDENT_H
#define STUDENT_H


#include "Person.h"
#include "Professor.h"
#include "Course.h"  
#include <unordered_map>
#include <vector>

class Course; // Forward declaration


class Student : public Person {
private:
    int currentSemester;
    std::string professor;
    std::vector<std::string> enrolledCourses; 
    float totalCredits; 
    std::unordered_map<std::string, int> courseSemesters;
    int grade;

public:
    // Constructors
    Student();
    Student(const std::string &name, int age, const std::string &studentID, float grade,
            int currentSemester, const std::string &professor);

    // Destructor
    ~Student();

    // Accessors
    int getSemester() const;
    std::string getProfessor() const;
    const std::vector<std::string>& getEnrolledCourses() const; 
    float getTotalCredits() const;

    // Mutators
    void setSemester(int currentSemester);
    void setProfessor(const std::string &professor);

    // Overriding the << operator for convenient output
    friend std::ostream &operator<<(std::ostream &out, const Student &student);
    
    void enrollInCourse(const Course& course);

    void enterGradeForCourse(const std::string& courseName, float grade);

    bool graduate();

    void enrollInCourseForCurrentSemester(const std::string& courseName);

    void modifyStudent(const std::string& newName, int newAge);
    
};

#endif 
