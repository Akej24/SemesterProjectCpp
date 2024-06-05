#ifndef EMPLOYEESERVICE
#define EMPLOYEESERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "Utlis.hpp"
#include "Validator.hpp"
#include "ServiceHelper.hpp"
#include <iostream>
#include <string_view>
#include <vector>

using namespace std;

class EmployeeService final {
private:
    EmployeeService() { }
    EmployeeService(const EmployeeService&) = delete;
    EmployeeService& operator=(const EmployeeService&) = delete;
    
public:
    static EmployeeService& getInstance() {
        static EmployeeService instance;
        return instance;
    }
    void createEmployee(vector<Person *> &employees, int id, bool withProject);
    void deleteEmployeeFromVector(vector<Person *> &employees);
    void addProjectToEmployee(const vector<Person *> &employees);
    void deleteEmployeeProject(const vector<Person *> &employees);
    void cloneEmployee(vector<Person *> &employees);
    void calculateEmployeeSalary(const vector<Person *> &employees);
    void showEmployeeProjectsAmount(const vector<Person *> &employees);
    void generateEmployeePresentation(const vector<Person *> &employees);
    void addLanguageToEmployee(const vector<Person *> &employees);
    void removeLanguageFromEmployee(const vector<Person *> &employees);
    void showEmployeeLanguages(const vector<Person *> &employees);
};

#endif