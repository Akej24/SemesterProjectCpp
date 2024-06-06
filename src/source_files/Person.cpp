#include "../header_files/Person.hpp"

void Person::updateAddress(string street_address, string city, string postal_code) { 
    delete address;
    this->address = new Address(street_address, city, postal_code); 
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    delete address;
    id = other.id;
    name = other.name;
    age = other.age;
    firstName = firstName;
    lastName = lastName;
    address = new Address(*other.address);
    return *this;
}