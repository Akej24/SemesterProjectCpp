#include "employee.h"
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

void createEmployee(vector<Employee *> &employees, int id);
void addProjectToEmployee(const vector<Employee *> &employees);
void showEmployeeInfo(const vector<Employee *> &employees);

void calculateEmployeeSalary(const vector<Employee *> &employees);
void showEmployeeProjectsAmount(const vector<Employee *> &employees);

void generateEmployeePresentation(const vector<Employee *> &employees);
void saveEmployeeProjectsSentenceToRecords(const vector<Employee *> &employees, string_view *Rekordy);