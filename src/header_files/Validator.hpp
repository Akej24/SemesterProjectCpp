#ifndef VALIDATOR
#define VALIDATOR

#include <iostream>
#include <string>
#include <vector>
#include "Person.hpp"
#include "Employee.hpp"
#include "Boss.hpp"
#include <memory>

using namespace std;

class Validator final {
private:
    Validator();

public:
    static bool isEmployee(shared_ptr<Person> person);
    static bool isBoss(shared_ptr<Person> person);
    static bool checkValidPersonIndex(int personIndex, int peopleSize);
    static bool checkAnyPersonExists(const vector<shared_ptr<Person>> &people);
};

#endif