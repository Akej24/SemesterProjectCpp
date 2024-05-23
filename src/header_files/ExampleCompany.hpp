#ifndef COMPANY
#define COMPANY

#include "Employee.hpp"
#include <iostream>

using namespace std;

class ExampleCompany {
private:
    static Employee* employees;
    static void initEmployees(); 
public:
    static void example();
};

#endif