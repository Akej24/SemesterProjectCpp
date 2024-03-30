#ifndef VALIDATOR
#define VALIDATOR

#include <string>
#include <iostream>
#include <vector>
#include "Employee.hpp"

using namespace std;

bool checkValidEmployeeIndex(int employeeIndex, int employeesSize);

bool checkAnyEmployeeExists(const vector<Employee *> &employees);

#endif