#ifndef BOSS
#define BOSS

#include <iostream>
#include <string>
#include <tuple>
#include "Person.hpp"
#include "Employee.hpp"
#include <memory>

using namespace std;    

//using BossInitializationData = tuple<int, string, int, string, string, string, Address *>;

class Boss final : public Person {
private:
    string title;
    
public:
    //Boss(BossInitializationData initializationData);
    Boss(int id, const string& name, int age, const string& firstName, const string& lastName, Address *address, const string& title)
        : Person(id, name, age, firstName, lastName, address), title(title) {}
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