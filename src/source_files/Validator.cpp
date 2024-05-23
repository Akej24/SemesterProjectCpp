#include "../header_files/Validator.hpp"

bool Validator::isEmployee(Person* person) {
    if (dynamic_cast<Employee*>(person)) return true;
    else return false;
}

bool Validator::isBoss(Person* person) {
    if (dynamic_cast<Boss*>(person)) return true;
    else return false;
}

bool Validator::checkValidPersonIndex(int personIndex, int peopleSize) {
    if (personIndex >= 0 && personIndex < peopleSize)
        return true;
    else {
        cout << "Niepoprawny indeks osoby!" << endl;
        return false;
    }
}

bool Validator::checkAnyPersonExists(const vector<Person *> &people) {
    if (people.empty()) {
        cout << "Brak ludzi do wyswietlenia!" << endl;
        return false;
    } else
        return true;
}