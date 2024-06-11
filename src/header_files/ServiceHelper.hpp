#ifndef SERVICEHELPER
#define SERVICEHELPER

#include "Person.hpp"
#include "Validator.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class ServiceHelper final {
private:
    ServiceHelper();
    
public:
    static int handleGetEmployeeIndex(const vector<shared_ptr<Person>> &people);
    static int handleGetBossIndex(const vector<shared_ptr<Person>> &people);
    static int handleGetPersonIndex(const vector<shared_ptr<Person>> &people);
};

#endif