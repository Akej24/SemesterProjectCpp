#include "../header_files/BossService.hpp"

void BossService::createBoss(vector<shared_ptr<Person>> &people, int id) {
    int age;
    string name, firstName, lastName, street_address, city, postal_code, title;
    shared_ptr<Address> address;

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

    BossInitializationData data = make_tuple(id, name, age, firstName, lastName, title, address);
    people.push_back(make_shared<Boss>(data));
}

void BossService::deleteBossFromVector(vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetBossIndex(people);
    if (personIndex == -1)
        return;
    people[personIndex].reset();
    people.erase(people.begin() + personIndex);
}

void BossService::giveRaise(vector<shared_ptr<Person>> &people) {
    int bossIndex = ServiceHelper::handleGetBossIndex(people);
    if (bossIndex == -1)
        return;

    int employeeIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (employeeIndex == -1)
        return;
    
    dynamic_pointer_cast<Boss>(people[bossIndex]).get()->giveRaise(dynamic_pointer_cast<Employee>(people[employeeIndex]));
}