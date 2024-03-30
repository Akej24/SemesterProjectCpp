#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <string>
#include "Address.hpp"
#include "Department.hpp"
#include "Project.hpp"
#include "Utlis.hpp"

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

void create(Employee *&employee);
void initialize(Employee *&employee, int id, string name, int age, string firstName, string lastName, int workedHours, double salaryPerHour, Address address, Department department, Project **projects);
void deleteEmployee(Employee *&employee);
void add(Project *project, Employee *employee);
void show(Employee *employee);

void presentEmployee(const Employee &employee);
double calculateSalary(Employee *employee);
int countProjects(Employee *employee);

#endif