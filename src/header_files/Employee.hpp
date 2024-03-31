#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <string>
#include <tuple>
#include "Address.hpp"
#include "Department.hpp"
#include "Project.hpp"
#include "Utlis.hpp"

using namespace std;

using InitializationDataWithProject = tuple<int, string, int, string, string, int, double, Address *, Department *, Project **>;
using InitializationData = tuple<int, string, int, string, string, int, double, Address *, Department *>;

class Employee {
private:
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    int workedHours;
    double salaryPerHour;
    Address *address;
    Department *department;
    Project **projects;

public:
    Employee(InitializationDataWithProject initializationDataWithProject);
    Employee(InitializationData initializationData);

    void deleteEmployee();
    void addProject(Project *project);
    void show();
    void presentEmployee();
    double calculateSalary() const;
    int countProjects() const;

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getWorkedHours() const { return workedHours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    Address getAddress() const { return *address; }
    Department getDepartment() const { return *department; }
    Project **getProjects() const { return projects; }
};

#endif