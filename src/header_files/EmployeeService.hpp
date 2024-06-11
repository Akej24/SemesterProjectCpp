#ifndef EMPLOYEESERVICE
#define EMPLOYEESERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "Utils.hpp"
#include "Validator.hpp"
#include "ServiceHelper.hpp"
#include <iostream>
#include <string_view>
#include <vector>
#include <memory>

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
    void createEmployee(vector<shared_ptr<Person>> &employees, int id, bool withProject);
    void deleteEmployeeFromVector(vector<shared_ptr<Person>> &employees);
    void addProjectToEmployee(const vector<shared_ptr<Person>> &employees);
    void deleteEmployeeProject(const vector<shared_ptr<Person>> &employees);
    void cloneEmployee(vector<shared_ptr<Person>> &employees);
    void calculateEmployeeSalary(const vector<shared_ptr<Person>> &employees);
    void showEmployeeProjectsAmount(const vector<shared_ptr<Person>> &employees);
    void generateEmployeePresentation(const vector<shared_ptr<Person>> &employees);
    void addLanguageToEmployee(const vector<shared_ptr<Person>> &employees);
    void removeLanguageFromEmployee(const vector<shared_ptr<Person>> &employees);
    void showEmployeeLanguages(const vector<shared_ptr<Person>> &employees);
};

#endif