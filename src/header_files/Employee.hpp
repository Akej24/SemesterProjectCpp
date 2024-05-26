#ifndef EMPLOYEE
#define EMPLOYEE

#include "Department.hpp"
#include "Person.hpp"
#include "Project.hpp"
#include "Utlis.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

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

    Employee(const Employee &other) : Person(other), workedHours(other.workedHours), salaryPerHour(other.salaryPerHour), hasRaise(other.hasRaise), department(other.department) {
        if (other.projects) {
            int numProjects = countProjects();
            projects = new Project *[numProjects];
            for (int i = 0; i < numProjects; ++i)
                projects[i] = other.projects[i];
        } else
            projects = nullptr;
    }

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

    class KnownProgrammingLanguages {
    private:
        vector<string> languages;

    public:
        explicit KnownProgrammingLanguages() {}
        void addLanguage(const string &language);
        void removeLanguage(const string &language);
        void showLanguages() const;    
        bool containsString(const string &str) const;
    };

    KnownProgrammingLanguages programmingLanguages;

    Employee &operator=(const Employee &other);
    Employee *operator[](int index);
    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);

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