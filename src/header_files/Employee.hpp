#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <string>
#include <tuple>
#include "Person.hpp"
#include "Department.hpp"
#include "Project.hpp"
#include "Utlis.hpp"

using namespace std;

using EmployeeInitializationDataWithProject = tuple<int, string, int, string, string, int, double, Address *, Department *, Project **>;
using EmployeeInitializationData = tuple<int, string, int, string, string, int, double, Address *, Department *>;

class Employee final : public Person {
private:
    int workedHours;
    double salaryPerHour;
    bool hasRaise = false;
    Department *department;
    Project **projects;

public:
    Employee(EmployeeInitializationDataWithProject initializationDataWithProject);
    Employee(EmployeeInitializationData initializationData);
    void show() const final override {
        cout << "ID: " << id << "\n";
        cout << "Imie: " << name << "\n";
        cout << "Wiek: " << age << "\n";
        cout << "Imie: " << firstName << "\n";
        cout << "Nazwisko: " << lastName << "\n";
        cout << "Przepracowane godziny: " << workedHours << "\n";
        cout << "Pensja na godzine: " << salaryPerHour << "\n";
        cout << "Adres: " << address->getStreetAddress() << ", " << address->getCity() << ", " << address->getPostalCode() << "\n";
        cout << "Oddzial: " << department->getName() << " (ID: " << department->getDepartmentId() << ")" << endl;
    }

    void deleteEmployee();
    void addProject(Project *project);
    void deleteProject(Project *project);

    void presentEmployee();
    double calculateSalary() const;
    int countProjects() const;

    int getWorkedHours() const { return workedHours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    Department getDepartment() const { return *department; }
    Project **getProjects() const { return projects; }
    void setRaise(bool hasRaise) { this->hasRaise = hasRaise; }
};

#endif