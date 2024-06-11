#include "../header_files/Person.hpp"

void Person::updateAddress(const string street_address, const string city, const string postal_code) {
    address = make_unique<Address>(street_address, city, postal_code); 
}
// Person::Person(const Person &other)
//     : id(other.id),
//       name(other.name),
//       age(other.age),
//       firstName(other.firstName),
//       lastName(other.lastName),
//       address(make_unique<Address>(*other.address))
// { }

Person& Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    age = other.age;
    firstName = other.firstName;
    lastName = other.lastName;
    address = make_unique<Address>(*other.address);
    return *this;
}