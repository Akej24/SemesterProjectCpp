#ifndef VALIDATOR
#define VALIDATOR

#include <string>
#include <iostream>
#include <vector>
#include "Employee.hpp"

using namespace std;

class Validator {
private: 
    Validator();
public:
    static bool checkValidEmployeeIndex(int employeeIndex, int employeesSize);
    static bool checkAnyEmployeeExists(const vector<Employee *> &employees);
};

#endif