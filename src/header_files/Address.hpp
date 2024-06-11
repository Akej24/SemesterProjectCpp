#ifndef ADDRESS
#define ADDRESS

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Address final {
private:
    string streetAddress;
    string city;
    string postalCode;

public:
    Address(string streetAddress, string city, string postalCode) : streetAddress(streetAddress), city(city), postalCode(postalCode) {}
    ~Address();
    string getCity() const { return city; }
    string getStreetAddress() const { return streetAddress; }
    string getPostalCode() const { return postalCode; }
    friend istream &operator>>(istream &is, unique_ptr<Address> &address);
};

#endif