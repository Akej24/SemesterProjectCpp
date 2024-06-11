#include "../header_files/Validator.hpp"

bool Validator::isEmployee(shared_ptr<Person> person) {
    if (dynamic_pointer_cast<Employee>(person)) return true;
    else return false;
}

bool Validator::isBoss(shared_ptr<Person> person) {
    if (dynamic_pointer_cast<Boss>(person)) return true;
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

bool Validator::checkAnyPersonExists(const vector<shared_ptr<Person>> &people) {
    if (people.empty()) {
        cout << "Brak ludzi do wyswietlenia!" << endl;
        return false;
    } else
        return true;
}