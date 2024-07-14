#include <iostream>
#include <fstream>
#include <sstream>
#include "Secretary.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include <algorithm>


void loadFromFile(const std::string& filename, Secretary& secretary) {
    std::ifstream file(filename);
    if (file.is_open()) {
        Person* person = nullptr;
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string role;

            iss >> role;

            if (role == "Student") {
                person = new Student();
            } else if (role == "Professor") {
                person = new Professor();
            } else {
                // Handle other roles if needed
            }

            if (person) {
                iss >> *person;
                secretary += person;
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void saveToFile(const std::string& filename, const Secretary& secretary) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << secretary;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add/Update/Delete Professor\n";
    std::cout << "2. Add/Update/Delete Student\n";
    std::cout << "3. Add/Update/Delete Course\n";
    std::cout << "4. Display Department Members\n";
    std::cout << "5. EnrollInCourse\n";
    std::cout << "6. Display and Save Students Passing a Course\n";
    std::cout << "7. Save Data to File\n";
    std::cout << "8. Quit\n";
}

void addOrUpdateProfessor(Secretary& secretary) {
    Professor professor;
    std::cin >> professor;

    try {
        secretary += new Professor(professor);
        std::cout << "Professor added/updated successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void addOrUpdateStudent(Secretary& secretary) {
    Student student;
    std::cin >> student;

    try {
        secretary += new Student(student);
        std::cout << "Student added/updated successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void addOrUpdateCourse(Secretary& secretary) {
    Course course;
    course.inputCourse();  // basic elements of course 

    // input numbers of professors
    int numOfProfessors;
    std::cout << "Enter the number of professors for the course: ";
    std::cin >> numOfProfessors;

for (int i = 0; i < numOfProfessors; ++i) {
    std::string professorName;
    std::cout << "Enter the name of the existing professor: ";
    std::cin >> professorName;

    // search of professor in existing
    Professor* professor = nullptr;
    for (Person* person : secretary.getDepartmentMembers()) {
        if (person->getRole() == "Professor" && person->getName() == professorName) {
            professor = dynamic_cast<Professor*>(person);
            break;
        }
    }

    if (professor) {
        // add professor to course
        course.addProfessor(professor);
    } else {
        std::cout << "Professor not found. Please make sure the professor exists.\n";
    }
}try {
        // add course to secretary
        secretary.addCourse(course);

        std::string courseName = course.getName();
        int semester; 
        
        std::string professorName;
        std::cout << "Enter the name of the professor to assign the course: ";
        std::cin >> professorName;
        Professor* professor = nullptr;
        for (Person* person : secretary.getDepartmentMembers()) {
            if (person->getRole() == "Professor" && person->getName() == professorName) {
                professor = dynamic_cast<Professor*>(person);
                break;
            }
        }

        if (professor) {
        
            secretary.assignProfessorToCourse(courseName, professor, semester);
            std::cout << "Το μάθημα ανατέθηκε με επιτυχία.\n";
        } else {
            std::cout << "Ο καθηγητής δεν βρέθηκε.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void enrollStudentInCourse(Secretary& secretary) {
    std::string studentName;
    std::cout << "Enter the name of the student: ";
    std::cin >> studentName;

    // Find the student in the department members
    Student* student = nullptr;
    for (Person* person : secretary.getDepartmentMembers()) {
        if (person->getRole() == "Student" && person->getName() == studentName) {
            student = dynamic_cast<Student*>(person);
            break;
        }
    }

    // Check if the student was found
    if (student) {
        std::string courseName;
        std::cout << "Enter the name of the course to enroll the student: ";
        std::cin >> courseName;

        // Find the course in the department members
        Course* course = nullptr;
        for (Person* person : secretary.getDepartmentMembers()) {
            if (person->getRole() == "Course" && person->getName() == courseName) {
                course = dynamic_cast<Course*>(person);
                break;
            }
        }

        // Check if the course was found
        if (course) {
            // Enroll the student in the course
            student->enrollInCourse(*course);
            std::cout << "Student enrolled in the course successfully.\n";
        } else {
            std::cout << "Course not found.\n";
        }
    } else {
        std::cout << "Student not found.\n";
    }
}

int main() {
    Secretary secretary;

    // Load data from files
    loadFromFile("students.txt", secretary);
    loadFromFile("professors.txt", secretary);
    loadFromFile("courses.txt", secretary);

    Student* student = nullptr;
    std::string studentName;

    Course* course = nullptr;
    std::string courseName;
    
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Professor menu
                std::cout << "1. Add Professor" << std::endl;
                std::cout << "2. Modify Professor" << std::endl;
                std::cout << "3. Delete Professor" << std::endl;
                
                int professorChoice;
                std::cout << "Enter your choice: ";
                std::cin >> professorChoice;
                
                if (professorChoice == 1) {
                    addOrUpdateProfessor(secretary);
                }
                else if (professorChoice == 2) {
                    std::string name, new_name, role;
                        int age, new_age;

                        std::cout << "Enter the name of the person you want to modify: ";
                        std::cin >> name;

                        Person* person = nullptr;
                        for (Person* p : secretary.getDepartmentMembers()) {
                            if (p->getName() == name) {
                                person = p;
                                role = p->getRole();
                                break;
                            }
                        }

                        if (person && role == "Professor") {
                            std::cout << "Enter the new name: ";
                            std::cin >> new_name;
                            std::cout << "Enter the new age: ";
                            std::cin >> new_age;
                            dynamic_cast<Professor*>(person)->modifyProfessor(new_name, new_age, "");
                            std::cout << "Professor modified successfully." << std::endl;
                        } else {
                            std::cout << "Professor not found." << std::endl;
                        }
                    } 
                // Delete Professor
                else if (professorChoice == 3) {
                    
                }
                break;

            case 2:
                // Student menu
                std::cout << "1. Add Student" << std::endl;
                std::cout << "2. Modify Student" << std::endl;
                std::cout << "3. Delete Student" << std::endl;

                int studentChoice;
                std::cout << "Enter your choice: ";
                std::cin >> studentChoice;

                // Add Student
                if (studentChoice == 1) {
                    addOrUpdateStudent(secretary);
                } 
                // Modify Student
                else if (studentChoice == 2) {
                    std::string name, new_name, professor;
                    int age, new_age;

                    std::cout << "Enter the name of the student you want to modify: ";
                    std::cin >> name;

                    Student* student = nullptr;

                    // Find the student with the given name
                    for (Person* p : secretary.getDepartmentMembers()) {
                        if (p->getName() == name && p->getRole() == "Student") {
                            student = dynamic_cast<Student*>(p);
                            break;
                        }
                    }

                    if (student) {
                        std::cout << "Enter the new name: ";
                        std::cin >> new_name;
                        std::cout << "Enter the new age: ";
                        std::cin >> new_age;

                        // Modify Student
                        student->modifyStudent(new_name, new_age);
                        std::cout << "Student modified successfully." << std::endl;
                    } else {
                        std::cout << "Student not found." << std::endl;
                    }
                } 
                // Delete Student
                else if (studentChoice == 3) {
                    
                }
                break;
            
            
            case 3:
                // Course menu
                std::cout << "1. Add Course" << std::endl;
                std::cout << "2. Modify Course" << std::endl;
                std::cout << "3. Delete Course" << std::endl;

                int courseChoice;
                std::cout << "Enter your choice: ";
                std::cin >> courseChoice;
                
                if (courseChoice == 1) {
                    addOrUpdateCourse(secretary);
                } 
                // Modify Student
                else if (courseChoice == 2) {
                    break;
                } 
                // Delete Student
                else if (courseChoice == 3) {
                    
                }
                break;
                
            case 4:
            // display
                std::cout << secretary;
                break;
            case 5:
                enrollStudentInCourse(secretary);
                break;
            case 6:
                
                break;
            case 7:
                saveToFile("output.txt", secretary);
                std::cout << "Data saved to file.\n";
                break;
            case 8:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
        }
     } while (choice != 8);

    return 0;
}


 