#ifndef PERSONSERVICE
#define PERSONSERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "Utlis.hpp"
#include "Validator.hpp"
#include "ServiceHelper.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PersonService final {
private:
    PersonService();
public:
    void static showPersonInfo(const vector<Person *> &people);
    void static saveEmployeeProjectsSentenceToRecords(const vector<Person *> &people, string *records);
    void static updateAddress(const vector<Person *> &people);
};

#endif