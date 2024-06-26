#include "../header_files/Address.hpp"

Address::~Address() { 
    cout << "Adres zostal usuniety" << endl; 
}

istream &operator>>(istream &is, shared_ptr<Address> &address) {
    string streetAddress, city, postalCode;
    cout << "Podaj adres:\n";
    cout << "a) Ulica: ";
    is >> streetAddress;
    cout << "b) Miasto: ";
    is >> city;
    cout << "c) Kod pocztowy: ";
    is >> postalCode;

    address = make_shared<Address>(streetAddress, city, postalCode);
    return is;
}