#ifndef VALIDATOR
#define VALIDATOR

#include <iostream>
#include <string>
#include <vector>
#include "Person.hpp"
#include "Employee.hpp"
#include "Boss.hpp"

using namespace std;

class Validator final {
private:
    Validator();

public:
    static bool isEmployee(Person* person);
    static bool isBoss(Person* person);
    static bool checkValidPersonIndex(int personIndex, int peopleSize);
    static bool checkAnyPersonExists(const vector<Person *> &people);
};

#endif