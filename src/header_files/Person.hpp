#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>
#include <tuple>
#include <memory>
#include "Address.hpp"

using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    shared_ptr<Address> address;

public:
    Person(int id, const string& name, int age, const string& firstName, const string& lastName, Address* address)
        : id(id), name(name), age(age), firstName(firstName), lastName(lastName), address(address) {}


    virtual ~Person() = default;
    virtual void show() const = 0;
    virtual string generateSentence() const = 0;
    void updateAddress(string street_address, string city, string postal_code);
    Person &operator=(const Person &other);
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Address getAddress() const { return *address; }
};

#endif