#ifndef ADDRESS
#define ADDRESS

#include <string>
#include <iostream>

using namespace std;

class Address final {
private:
    string streetAddress;
    string city;
    string postalCode;

public:
    Address(string streetAddress, string city, string postalCode) : streetAddress(streetAddress), city(city), postalCode(postalCode) {}
    ~Address() { cout << "Adres zostal usuniety" << endl; }
    string getCity() const { return city; }
    string getStreetAddress() const { return streetAddress; }
    string getPostalCode() const { return postalCode; }
};

#endif