#include "../header_files/PersonService.hpp"

void PersonService::showPersonInfo(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetPersonIndex(people);
    if (personIndex == -1)
        return;
    people[personIndex].get()->show();  //polymporphism
}

void PersonService::savePersonToRecords(const vector<shared_ptr<Person>> &people, string *records) {
    int personIndex = ServiceHelper::handleGetPersonIndex(people);
    if (personIndex == -1)
        return;

    records[personIndex] = people[personIndex].get()->generateSentence(); //polymporphism
    cout << "Pomyslnie zapisano, aktualne rekordy: " << endl;
    for (int i = 0; i < people.size(); i++)
        if (!records[i].empty())
            cout << "Rekord " << i << ": " << records[i] << endl;
}

void PersonService::updateAddress(const vector<shared_ptr<Person>> &people) {
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

    people[personIndex].get()->updateAddress(street_address, city, postal_code);
}