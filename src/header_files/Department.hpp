#ifndef DEPARTMENT
#define DEPARTMENT

#include <string>
#include <iostream>

using namespace std;

class Department final {
private:
    string name;
    int departmentId;

public:
    Department(string name, int departmentId) : name(name), departmentId(departmentId) {}
    ~Department() { cout << "Oddzial zostal usuniety" << endl; }
    string getName() const { return name; }
    int getDepartmentId() const { return departmentId; }
};
#endif