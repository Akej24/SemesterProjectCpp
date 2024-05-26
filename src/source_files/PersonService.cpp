#include "../header_files/PersonService.hpp"

void PersonService::showPersonInfo(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetPersonIndex(people);
    if (personIndex == -1)
        return;
    people[personIndex]->show();
}

void PersonService::savePersonToRecords(const vector<Person *> &people, string *records) {
    int personIndex = ServiceHelper::handleGetPersonIndex(people);
    if (personIndex == -1)
        return;

    if (auto *employee = dynamic_cast<Employee *>(people[personIndex]))
        records[personIndex] = "Employee " + employee->getFirstName() + " " + Utils::capitalizeFirstLetter(employee->getLastName()) + " has " + to_string(employee->countProjects()) + " projects.";
    else if (auto *boss = dynamic_cast<Boss *>(people[personIndex]))
        records[personIndex] = "Boss " + boss->getFirstName() + " " + Utils::capitalizeFirstLetter(boss->getLastName()) + " has title " + boss->getTitle();

    cout << "Pomyslnie zapisano, aktualne rekordy: " << endl;
    for (int i = 0; i < people.size(); i++)
        if (!records[i].empty())
            cout << "Rekord " << i << ": " << records[i] << endl;
}

void PersonService::updateAddress(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetPersonIndex(people);
    if (personIndex == -1)
        return;

    string street_address, city, postal_code;
    cout << "Podaj nowy adres:\n";
    cout << "a) Ulica: ";
    cin >> street_address;
    cout << "b) Miasto: ";
    cin >> city;
    cout << "c) Kod pocztowy: ";
    cin >> postal_code;

    people[personIndex]->updateAddress(street_address, city, postal_code);
}