#include "../header_files/Boss.hpp"

Boss::Boss(BossInitializationData data) {
    tie(id, name, age, firstName, lastName, title, address) = data;
}

void Boss::deleteBoss() {
    delete this;
}

void Boss::giveRaise(Employee *employee) {
    employee->setRaise(true);
}