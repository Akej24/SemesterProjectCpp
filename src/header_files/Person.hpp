#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>
#include <tuple>
#include "Address.hpp"

using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    Address *address;

public:
    virtual ~Person() = default; // if not definied than 'delete people[0]; would not call matching type (e.g. when deleting person who is employee will not call employee destructor)
    virtual void show() const = 0;
    void updateAddress(string street_address, string city, string postal_code) { this->address = new Address(street_address, city, postal_code); }
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Address getAddress() const { return *address; }
};

#endif