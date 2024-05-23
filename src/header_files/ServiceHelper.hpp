#ifndef SERVICEHELPER
#define SERVICEHELPER

#include "Person.hpp"
#include "Validator.hpp"
#include <iostream>
#include <vector>

using namespace std;

class ServiceHelper final {
private:
    ServiceHelper();
public:
    static int handleGetEmployeeIndex(const vector<Person *> &people);
    static int handleGetBossIndex(const vector<Person *> &people);
    static int handleGetPersonIndex(const vector<Person *> &people);
};

#endif