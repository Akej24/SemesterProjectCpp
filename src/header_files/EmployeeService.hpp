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
    EmployeeService();
public:
    void static createEmployee(vector<Person *> &employees, int id, bool withProject);
    void static deleteEmployeeFromVector(vector<Person *> &employees);
    void static addProjectToEmployee(const vector<Person *> &employees);
    void static deleteEmployeeProject(const vector<Person *> &employees);

    void static calculateEmployeeSalary(const vector<Person *> &employees);
    void static showEmployeeProjectsAmount(const vector<Person *> &employees);

    void static generateEmployeePresentation(const vector<Person *> &employees);
};

#endif