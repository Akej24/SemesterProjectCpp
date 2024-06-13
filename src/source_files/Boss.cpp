#include "../header_files/Boss.hpp"

Boss::Boss(const BossInitializationData& data)
    : Person(get<0>(data), get<1>(data), get<2>(data), get<3>(data), get<4>(data), shared_ptr<Address>(get<6>(data))),
    title(get<5>(data)) {}

Boss::~Boss() {
    cout << "Zostalem usuniety jako szef" << endl;
}

void Boss::show() const {
    cout << "ID: " << id << "\n";
    cout << "Imie: " << name << "\n";
    cout << "Wiek: " << age << "\n";
    cout << "Imie: " << firstName << "\n";
    cout << "Nazwisko: " << lastName << "\n";
    cout << "Tytul: " << title << "\n";
    cout << "Adres: " << address->getStreetAddress() << ", " << address->getCity() << ", " << address->getPostalCode() << "\n";
}

string Boss::generateSentence() const {
    return "Boss " + firstName + " " + Utils::capitalizeFirstLetter(lastName) + " has title " + title;
}

void Boss::giveRaise(shared_ptr<Employee> employee) {
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