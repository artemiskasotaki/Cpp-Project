#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Professor.h"

class Professor;

class Course {
private:
    std::string name;
    int semester;
    int teachingUnits;
    bool mandatory;
    std::vector<Professor*> professors;
    
    

public:
    // Constructors
    Course();
    Course(const std::string &name, int semester, int teachingUnits, bool mandatory);

    // Destructor
    ~Course();

    // Accessors
    std::string getName() const;
    int getSemester() const;
    int getTeachingUnits() const;
    bool isMandatory() const;

    // Mutators
    void setName(const std::string &name);
    void setSemester(int semester);
    void setTeachingUnits(int teachingUnits);
    void setMandatory(bool mandatory);

    void moveCourseToSemester(int newSemester);

    bool isAvailableForEnrollment(int studentSemester) const;

    void inputCourse();
    
    void addProfessor(const Professor* professor);

    void assignProfessor(Professor* professor, int semester);
    const std::vector<Professor*>& getProfessors() const;
};

#endif // COURSE_H
