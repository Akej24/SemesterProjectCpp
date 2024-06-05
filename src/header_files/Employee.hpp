#ifndef EMPLOYEE
#define EMPLOYEE

#include "Department.hpp"
#include "Person.hpp"
#include "Project.hpp"
#include "Utlis.hpp"
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

using EmployeeInitializationDataWithProject = tuple<int, string, int, string, string, int, double, Address *, Department *, vector<Project *>>;
using EmployeeInitializationData = tuple<int, string, int, string, string, int, double, Address *, Department *>;
using ProjectMatcher = function<bool(const Project *)>;

class Employee final : public Person {
private:
    int workedHours;
    double salaryPerHour;
    bool hasRaise = false;
    Department *department;
    vector<Project *> projects;

public:
    Employee(EmployeeInitializationDataWithProject initializationDataWithProject);
    Employee(EmployeeInitializationData initializationData);
    ~Employee() {
        delete department;
        for (auto project : projects)
            delete project;
        cout << "Zostalem usuniety jako pracownik" << endl;
    }
    Employee(const Employee &other) : Person(other), workedHours(other.workedHours), salaryPerHour(other.salaryPerHour), hasRaise(other.hasRaise), department(other.department) {
        projects.reserve(other.projects.size());
        for (const auto &project : other.projects)
            projects.emplace_back(project);
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
        set<string> languages;

    public:
        explicit KnownProgrammingLanguages() {}
        void addLanguage(const string &language);
        void removeLanguage(const string &language);
        void showLanguagesAlphabetic() const;
        bool containsString(const string &str) const;
        bool operator()(const string &a, const string &b) const {
            return a.length() > b.length();
        }
    };

    KnownProgrammingLanguages programmingLanguages;

    Employee &operator=(const Employee &other);
    Project *operator[](int index);
    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);
    void addProject(Project &project);
    void deleteProject(string projectName);
    void presentEmployee();
    double calculateSalary() const;
    int countProjects() const;
    int getWorkedHours() const { return workedHours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    Department getDepartment() const { return *department; }
    vector<Project *> getProjects() const { return projects; }
    void setRaise(bool hasRaise) { this->hasRaise = hasRaise; }
};

#endif