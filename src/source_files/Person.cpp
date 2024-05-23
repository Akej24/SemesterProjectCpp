#include "../header_files/Person.hpp"

void Person::updateAddress(string street_address, string city, string postal_code) {
    this->address = new Address(street_address, city, postal_code);
}