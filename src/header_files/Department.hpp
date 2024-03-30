#ifndef DEPARTMENT
#define DEPARTMENT

#include <string>

using namespace std;

class Department {
private:
    string name;
    int departmentId;

public:
    Department(string name, int departmentId)
        : name(name), departmentId(departmentId) {}

    string getName() const { return name; }
    int getDepartmentId() const { return departmentId; }
};
#endif