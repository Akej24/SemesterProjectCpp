#include "../header_files/Employee.hpp"

Employee::~Employee() {
    cout << "Zostalem usuniety jako pracownik" << endl;
}

void Employee::show() const {
    cout << "ID: " << id << "\n";
    cout << "Imie: " << name << "\n";
    cout << "Wiek: " << age << "\n";
    cout << "Imie: " << firstName << "\n";
    cout << "Nazwisko: " << lastName << "\n";
    cout << "Przepracowane godziny: " << workedHours << "\n";
    cout << "Pensja na godzine: " << salaryPerHour << "\n";
    cout << "Adres: " << address->getStreetAddress() << ", " << address->getCity() << ", " << address->getPostalCode() << "\n";
    cout << "Oddzial: " << department->getName() << " (ID: " << department->getDepartmentId() << ")" << endl;
    if (!projects.empty()) {
        cout << "Projekty: ";
        for (const auto& project : projects)
            cout << project->getName() << " ";
        cout << endl;
    }
}

string Employee::generateSentence() const {
    return "Employee " + firstName + " " + Utils::capitalizeFirstLetter(lastName) + " has " + to_string(this->countProjects()) + " projects.";
}

Employee::Employee(const Employee& other)
    : Person(other),
      workedHours(other.workedHours),
      salaryPerHour(other.salaryPerHour),
      hasRaise(other.hasRaise),
      department(make_unique<Department>(*other.department)) {
    projects.reserve(other.projects.size());
    for (const auto &project : other.projects)
        projects.emplace_back(make_shared<Project>(*project));
}

void Employee::addProject(Project &project) {
    projects.push_back(make_shared<Project>(project));
}

ProjectMatcher deleteIfEquals(const string &projectName) {
    return [=](const Project* p) {
        return p && *p == projectName;
    };
}

void Employee::deleteProject(string projectName) {
    projects.erase(
        remove_if(
            projects.begin(),
            projects.end(),
            [&](const shared_ptr<Project>& p) {
                return p->getName() == projectName;
            }),
        projects.end());
}

double Employee::calculateSalary() const {
    if (hasRaise)
        return workedHours * salaryPerHour + 1000;
    else
        return workedHours * salaryPerHour;
}

int Employee::countProjects() const {
    return projects.size();
}

void Employee::presentEmployee() {
    cout << "Employee " << firstName << " " << Utils::capitalizeFirstLetter(lastName)
         << " has " << age << " years old and works in department " << department->getName() << endl;
}

Employee& Employee::operator=(const Employee& other) {
    if (this == &other)
        return *this;

    Person::operator=(other);
    workedHours = other.workedHours;
    salaryPerHour = other.salaryPerHour;
    hasRaise = other.hasRaise;
    department = make_unique<Department>(*other.department);
    projects.clear();
    projects.reserve(other.projects.size());
    for (const auto& project : other.projects) {
        projects.emplace_back(make_shared<Project>(*project));
    }
    return *this;
}

shared_ptr<Project> Employee::operator[](int index) {
    if (index >= 0 && index < projects.size()) {
        return projects[index];
    } else {
        cout << "Index poza zasiegiem" << endl;
        return nullptr;
    }
}

ostream &operator<<(ostream &os, const Employee &employee) {
    os << "ID: " << employee.id << "\n";
    os << "Imie: " << employee.name << "\n";
    os << "Wiek: " << employee.age << "\n";
    os << "Imie: " << employee.firstName << "\n";
    os << "Nazwisko: " << employee.lastName << "\n";
    os << "Przepracowane godziny: " << employee.workedHours << "\n";
    os << "Pensja na godzine: " << employee.salaryPerHour << "\n";
    os << "Adres: " << employee.address->getStreetAddress() << ", " << employee.address->getCity() << ", " << employee.address->getPostalCode() << "\n";
    os << "Oddzial: " << employee.department->getName() << " (ID: " << employee.department->getDepartmentId() << ")\n";
    return os;
}

istream &operator>>(istream &is, Employee &employee) {
    is >> employee.id >> employee.name >> employee.age >> employee.firstName >> employee.lastName >> employee.workedHours >> employee.salaryPerHour;
    return is;
}

void Employee::KnownProgrammingLanguages::addLanguage(const string &language) {
    languages.insert(language);
}

void Employee::KnownProgrammingLanguages::removeLanguage(const string &language) {
    languages.erase(language);
}

struct AlphabeticLanguagesComparator {
    bool operator()(const string& a, const string& b) const {
        return a < b;
    }
};

void Employee::KnownProgrammingLanguages::showLanguagesAlphabetic() const {
    vector<string> languagesVector(languages.begin(), languages.end());
    sort(languagesVector.begin(), languagesVector.end(), AlphabeticLanguagesComparator());
    
    cout << "Znane jezyki programowania alfabetycznie: ";
    copy(languagesVector.begin(), languagesVector.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

bool Employee::KnownProgrammingLanguages::containsString(const string &str) const {
    return find(languages.begin(), languages.end(), str) != languages.end();
}

bool Employee::KnownProgrammingLanguages::operator()(const string &a, const string &b) const {
    return a.length() > b.length();
}