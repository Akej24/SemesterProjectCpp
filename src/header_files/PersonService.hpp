#ifndef PERSONSERVICE
#define PERSONSERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "ServiceHelper.hpp"
#include "Utils.hpp"
#include "Validator.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
    void showPersonInfo(const vector<shared_ptr<Person>>& people);
    void savePersonToRecords(const vector<shared_ptr<Person>>& people, string *records);
    void updateAddress(const vector<shared_ptr<Person>>& people);
};

#endif