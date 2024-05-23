#ifndef BOSSSERVICE
#define BOSSSERVICE

#include "Boss.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Records.hpp"
#include "Utlis.hpp"
#include "Validator.hpp"
#include "ServiceHelper.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BossService final {
private:
    BossService();

public:
    void static createBoss(vector<Person *> &people, int id);
    void static deleteBossFromVector(vector<Person *> &people);
    void static giveRaise(vector<Person *> &people);
};

#endif