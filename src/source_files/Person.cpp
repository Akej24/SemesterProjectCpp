#include "../header_files/Person.hpp"

void Person::updateAddress(string street_address, string city, string postal_code) {
    this->address = make_shared<Address>(street_address, city, postal_code); 
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    age = other.age;
    firstName = firstName;
    lastName = lastName;
    address = make_shared<Address>(*other.address);
    return *this;
}