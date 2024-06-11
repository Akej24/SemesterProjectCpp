#ifndef BOSS
#define BOSS

#include <iostream>
#include <string>
#include <tuple>
#include <memory>
#include "Person.hpp"
#include "Employee.hpp"

using namespace std;    

using BossInitializationData = tuple<int, string, int, string, string, string, unique_ptr<Address>>;

class Boss final : public Person {
private:
    string title;
    
public:
    Boss(BossInitializationData initializationData);
    ~Boss();
    void show() const final override;
    string generateSentence() const final override;
    Boss& operator=(const Boss& other);
    friend ostream& operator<<(ostream& os, const Boss& employee);
    friend istream& operator>>(istream& is, Boss& employee);
    void giveRaise(shared_ptr<Employee> employee);
    string getTitle() const { return title; }
};

#endif