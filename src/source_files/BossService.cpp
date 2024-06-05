#include "../header_files/BossService.hpp"

void BossService::createBoss(vector<Person *> &people, int id) {
    int age;
    string name, firstName, lastName, street_address, city, postal_code, title;
    Address* address;

    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    name = firstName + " " + lastName;
    cout << "Podaj wiek: ";
    cin >> age;
    cout << "Podaj tytul (pozycje) szefa: ";
    cin >> title;
    cin >> address;

    BossInitializationData data(id, name, age, firstName, lastName, title, address);
    people.push_back(new Boss(data));
}

void BossService::deleteBossFromVector(vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetBossIndex(people);
    if (personIndex == -1)
        return;
    delete dynamic_cast<Boss *>(people[personIndex]);
    people.erase(people.begin() + personIndex);
}

void BossService::giveRaise(vector<Person *> &people) {
    int bossIndex = ServiceHelper::handleGetBossIndex(people);
    if (bossIndex == -1)
        return;

    int employeeIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (employeeIndex == -1)
        return;
    
    dynamic_cast<Boss *>(people[bossIndex])->giveRaise(dynamic_cast<Employee *>(people[employeeIndex]));
}