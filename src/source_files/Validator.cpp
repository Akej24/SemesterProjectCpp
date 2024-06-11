#include "../header_files/Validator.hpp"

bool Validator::isEmployee(const shared_ptr<Person>& person) {
    return dynamic_cast<Employee*>(person.get()) != nullptr;
}

bool Validator::isBoss(const shared_ptr<Person>& person) {
    return dynamic_cast<Boss*>(person.get()) != nullptr;
}

bool Validator::checkValidPersonIndex(int personIndex, int peopleSize) {
    if (personIndex >= 0 && personIndex < peopleSize)
        return true;
    else {
        cout << "Niepoprawny indeks osoby!" << endl;
        return false;
    }
}

bool Validator::checkAnyPersonExists(const vector<shared_ptr<Person>>& people) {
    if (people.empty()) {
        cout << "Brak ludzi do wyswietlenia!" << endl;
        return false;
    } else
        return true;
}