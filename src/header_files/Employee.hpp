#ifndef EMPLOYEE
#define EMPLOYEE

#include "Address.hpp"
#include "Department.hpp"
#include "Project.hpp"
#include "Utlis.hpp"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

struct Employee {
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    int workedHours;
    double salaryPerHour;
    Address address;
    Department department;
    Project **projects;
};

using InitializationDataWithProject = tuple<Employee *&, int, string, int, string, string, int, double, Address, Department, Project **>;
using InitializationData = tuple<Employee *&, int, string, int, string, string, int, double, Address, Department>;

void initialize(InitializationDataWithProject initializationDataWithProject);
void initialize(InitializationData initializationData);
void deleteEmployee(Employee *&employee);
void add(Project *project, Employee *employee);
void show(Employee *employee);

void presentEmployee(const Employee &employee);
double calculateSalary(Employee *employee);
int countProjects(Employee *employee);

#endif