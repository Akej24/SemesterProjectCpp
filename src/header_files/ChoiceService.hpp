#ifndef CHOICESERVICE
#define CHOICESERVICE

#include <iostream>
#include <string_view>
#include <vector>
#include "Employee.hpp"
#include "Records.hpp"
#include "Utlis.hpp"
#include "Validator.hpp"

void createEmployee(vector<Employee *> &employees, int id);
void addProjectToEmployee(const vector<Employee *> &employees);
void showEmployeeInfo(const vector<Employee *> &employees);

void calculateEmployeeSalary(const vector<Employee *> &employees);
void showEmployeeProjectsAmount(const vector<Employee *> &employees);

void generateEmployeePresentation(const vector<Employee *> &employees);
void saveEmployeeProjectsSentenceToRecords(const vector<Employee *> &employees, string* records);
void extractAttributesFromRecords(const string *records, int size);

#endif