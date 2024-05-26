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
    PersonService() { }
    PersonService(const PersonService&) = delete;
    PersonService& operator=(const PersonService&) = delete;
public:
    static PersonService& getInstance() {
        static PersonService instance;
        return instance;
    }
    void showPersonInfo(const vector<Person *> &people);
    void savePersonToRecords(const vector<Person *> &people, string *records);
    void updateAddress(const vector<Person *> &people);
};

#endif