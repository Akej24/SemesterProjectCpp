#include "../header_files/ServiceHelper.hpp"

int ServiceHelper::handleGetEmployeeIndex(const vector<shared_ptr<Person>> &people) {
    if (!Validator::checkAnyPersonExists)
        return -1;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!Validator::checkValidPersonIndex(employeeIndex, people.size()) || !Validator::isEmployee(people[employeeIndex]))
        return -1;
    return employeeIndex;
}

int ServiceHelper::handleGetBossIndex(const vector<shared_ptr<Person>> &people) {
    if (!Validator::checkAnyPersonExists)
        return -1;

    int bossIndex;
    cout << "Wybierz indeks szefa: ";
    cin >> bossIndex;
    if (!Validator::checkValidPersonIndex(bossIndex, people.size()) || !Validator::isBoss(people[bossIndex]))
        return -1;
    return bossIndex;
}

int ServiceHelper::handleGetPersonIndex(const vector<shared_ptr<Person>> &people) {
    if (!Validator::checkAnyPersonExists)
        return -1;

    int personIndex;
    cout << "Wybierz indeks osoby (pracownika lub szefa): ";
    cin >> personIndex;
    if (!Validator::checkValidPersonIndex(personIndex, people.size()))
        return -1;
    return personIndex;
}