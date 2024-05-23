#ifndef PERSONSERVICE
#define PERSONSERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "ServiceHelper.hpp"
#include "Utlis.hpp"
#include "Validator.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PersonService final {
private:
    PersonService();

public:
    void static showPersonInfo(const vector<Person *> &people);
    void static savePersonToRecords(const vector<Person *> &people, string *records);
    void static updateAddress(const vector<Person *> &people);
};

#endif