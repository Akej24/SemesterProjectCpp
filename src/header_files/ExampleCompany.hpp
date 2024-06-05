#ifndef EXAMPLE_COMPANY_HPP
#define EXAMPLE_COMPANY_HPP

#include "Employee.hpp"
#include <array>

using namespace std;

class ExampleCompany {
private:
    array<Employee, 3> employees; // allocating on stack

public:
    ExampleCompany() : employees {
        Employee(EmployeeInitializationDataWithProject(1, "John Doe", 30, "John", "Doe", 159, 22.84, 
            new Address("Address1", "City1", "12-123"), 
            new Department("Department1", 1), 
            {new Project("TestProject1", 1, "TestOpis1")})),

        Employee(EmployeeInitializationDataWithProject(2, "Jane Smith", 25, "Jane", "Smith", 150, 19.43, 
            new Address("Address2", "City2", "12-123"), 
            new Department("Department2", 2),
            {new Project("TestProject2", 2, "TestOpis2")})),

        Employee(EmployeeInitializationDataWithProject(3, "Alice Johnson", 35, "Alice", "Johnson", 168, 28.43, 
            new Address("Address3", "City3", "12-123"), 
            new Department("Department3", 3),
            {new Project("TestProject3", 3, "TestOpis3")})),
    } { };
    void example();
};

#endif