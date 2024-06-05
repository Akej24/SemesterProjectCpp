#include "../header_files/Boss.hpp"

Boss::Boss(BossInitializationData data) {
    tie(id, name, age, firstName, lastName, title, address) = data;
}

void Boss::giveRaise(Employee *employee) {
    employee->setRaise(true);
}

Boss& Boss::operator=(const Boss& other) {
    if (this == &other)
        return *this;
    Boss::operator=(other);
    title = other.title;
    return *this;
}

ostream& operator<<(ostream& os, const Boss& boss) {
    os << "ID: " << boss.id << "\n";
    os << "Imie: " << boss.name << "\n";
    os << "Wiek: " << boss.age << "\n";
    os << "Imie: " << boss.firstName << "\n";
    os << "Nazwisko: " << boss.lastName << "\n";
    os << "Tytul: " << boss.title << "\n";
    os << "Adres: " << boss.address->getStreetAddress() << ", " << boss.address->getCity() << ", " << boss.address->getPostalCode() << "\n";
    return os;
}

istream& operator>>(istream& is, Boss& boss) {
    is >> boss.id >> boss.name >> boss.age >> boss.firstName >> boss.lastName >> boss.title;
    return is;
}