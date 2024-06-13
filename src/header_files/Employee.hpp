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
#include <memory>

using namespace std;

using EmployeeInitializationDataWithProject = tuple<int, string, int, string, string, int, double, shared_ptr<Address>, shared_ptr<Department>, vector<shared_ptr<Project>>>;
using EmployeeInitializationData = tuple<int, string, int, string, string, int, double, shared_ptr<Address>, shared_ptr<Department>>;
using ProjectMatcher = function<bool(const shared_ptr<Project>)>;

class Employee final : public Person {
private:
    int workedHours;
    double salaryPerHour;
    bool hasRaise = false;
    shared_ptr<Department> department;
    vector<shared_ptr<Project>> projects;

public:
    Employee(const EmployeeInitializationData& data);
    Employee(const EmployeeInitializationDataWithProject& data);
    ~Employee();
    Employee(const Employee &other);

    class KnownProgrammingLanguages {
    private:
        set<string, function<bool(const string&, const string&)>> languages;

    public:
        explicit KnownProgrammingLanguages() : languages([](const string& a, const string& b) { return a < b; }) {}
        void addLanguage(const string &language);
        void removeLanguage(const string &language);
        void showLanguages() const;
        bool containsString(const string &str) const;
    };

    KnownProgrammingLanguages programmingLanguages;
    void show() const final override;
    string generateSentence() const final override;
    Employee &operator=(const Employee &other);
    shared_ptr<Project> operator[](int index);
    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);
    void addProject(shared_ptr<Project> project);
    void deleteProject(string projectName);
    void presentEmployee();
    double calculateSalary() const;
    int countProjects() const;
    int getWorkedHours() const { return workedHours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    Department getDepartment() const { return *department; }
    vector<shared_ptr<Project>> getProjects() const { return projects; }
    void setRaise(bool hasRaise) { this->hasRaise = hasRaise; }
};

#endif