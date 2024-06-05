#ifndef EXAMPLE_COMPANY_HPP
#define EXAMPLE_COMPANY_HPP

#include "Employee.hpp"
#include <array>

using namespace std;

class ExampleCompany {
private:
    array<Employee, 3> employees; // allocating on stack

public:
    ExampleCompany();
    void example();
};

#endif