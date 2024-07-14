#include <iostream>
#include "Person.h"
#include "Secretary.h"

int main() {
    Person *student1 = new Person("Artemis", 22, "Student", "1115201900040", 6.7);
    Person *student2 = new Person("Stelios", 19, "Student", "1115202400051", 8.4);
    Person *teacher1 = new Person("Dr. Smith", 40, "Teacher");
    Person *student3 = new Person("John", 20, "Student", "1115202400053", 5);
    Person *student4 = new Person("Emma", 21, "Student", "67890", 7.3);
    Person *teacher2 = new Person("Dr. Alex", 45, "Teacher");

    
    Secretary departmentSecretary;


    departmentSecretary += student1;
    departmentSecretary += student2;
    departmentSecretary += student3;
    departmentSecretary += student4;
    departmentSecretary += teacher1;
    departmentSecretary += teacher2;


    std::cout << "Department Members:\n" << departmentSecretary << std::endl;

   
    std::cout << "Is Artemis in the department? " << std::boolalpha << departmentSecretary.findPerson("Artemis") << std::endl;
    std::cout << "Is Konstantinos in the department? " << std::boolalpha << departmentSecretary.findPerson("Konstantinos") << std::endl;

    std::cout << "Number of persons created: " << Person::getCount() << std::endl;

    
    delete student1;
    delete student2;
    delete student3;
    delete student4;
    delete teacher1;
    delete teacher2;

    return 0;
}
