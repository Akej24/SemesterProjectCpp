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
#include <memory>

using namespace std;

class BossService final {
private:
    BossService() { }
    BossService(const BossService&) = delete;
    BossService& operator=(const BossService&) = delete;
public:
    static BossService& getInstance() {
        static BossService instance;
        return instance;
    }
    void createBoss(vector<shared_ptr<Person>> &people, int id);
    void deleteBossFromVector(vector<shared_ptr<Person>> &people);
    void giveRaise(vector<shared_ptr<Person>> &people);
};

#endif