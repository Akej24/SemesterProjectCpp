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
    ~Employee();
    Employee(const Employee &other);

    class KnownProgrammingLanguages {
    private:
        set<string> languages;

    public:
        explicit KnownProgrammingLanguages() {}
        void addLanguage(const string &language);
        void removeLanguage(const string &language);
        void showLanguagesAlphabetic() const;
        bool containsString(const string &str) const;
        bool operator()(const string &a, const string &b) const;
    };

    KnownProgrammingLanguages programmingLanguages;
    void show() const final override;
    string generateSentence() const final override;
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