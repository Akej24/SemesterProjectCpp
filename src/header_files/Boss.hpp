#ifndef BOSS
#define BOSS

#include <iostream>
#include <string>
#include <tuple>
#include "Person.hpp"
#include "Employee.hpp"

using namespace std;    

using BossInitializationData = tuple<int, string, int, string, string, string, Address *>;

class Boss final : public Person {
private:
    string title;
    
public:
    Boss(BossInitializationData initializationData);
    void show() const final override {
        cout << "ID: " << id << "\n";
        cout << "Imie: " << name << "\n";
        cout << "Wiek: " << age << "\n";
        cout << "Imie: " << firstName << "\n";
        cout << "Nazwisko: " << lastName << "\n";
        cout << "Tytul: " << title << "\n";
        cout << "Adres: " << address->getStreetAddress() << ", " << address->getCity() << ", " << address->getPostalCode() << "\n";
    }

    Boss& operator=(const Boss& other);
    Boss* operator[](int index);  
    friend ostream& operator<<(ostream& os, const Boss& employee);
    friend istream& operator>>(istream& is, Boss& employee);

    void deleteBoss();
    void giveRaise(Employee *employee);
    string getTitle() const { return title; }
};

#endif