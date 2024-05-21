#include "../header_files/Employee.hpp"

Employee::Employee(InitializationDataWithProject data) {
    tie(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects) = data;
}

Employee::Employee(InitializationData data) {
    tie(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department) = data;
}

void Employee::deleteEmployee() {
    delete this;
}

void Employee::addProject(Project *project) {
    if (projects == nullptr) {
        projects = new Project *[2];
        projects[0] = project;
        projects[1] = nullptr;
    } else {
        int newSize = 0;
        while (projects[newSize] != nullptr)
            newSize++;
        newSize++;
        Project **newProjects = new Project *[newSize + 1];
        for (int i = 0; i < newSize - 1; ++i)
            newProjects[i] = projects[i];
        newProjects[newSize - 1] = project;
        newProjects[newSize] = nullptr;
        delete[] projects;
        projects = newProjects;
    }
}

void Employee::deleteProject(Project *project) {
    if (projects == nullptr)
        return;

    int foundProjectIndex = 0;
    while (projects[foundProjectIndex] != nullptr && projects[foundProjectIndex] != project)
        ++foundProjectIndex;

    if (projects[foundProjectIndex] == nullptr)
        return;

    delete projects[foundProjectIndex];
    for (int i = foundProjectIndex; projects[i] != nullptr; i++) {
        projects[i] = projects[i + 1];
    }

    if (projects[0] == nullptr) {
        delete[] projects;
        projects = nullptr;
    }
}

void Employee::show() {
    cout << "ID: " << id << "\n";
    cout << "Imie: " << name << "\n";
    cout << "Wiek: " << age << "\n";
    cout << "Imie: " << firstName << "\n";
    cout << "Nazwisko: " << lastName << "\n";
    cout << "Przepracowane godziny: " << workedHours << "\n";
    cout << "Pensja na godzine: " << salaryPerHour << "\n";
    cout << "Adres: " << address->getStreetAddress() << ", " << address->getCity() << ", " << address->getPostalCode() << "\n";
    cout << "Oddzial: " << department->getName() << " (ID: " << department->getDepartmentId() << ")" << endl;
}

double Employee::calculateSalary() const {
    return workedHours * salaryPerHour;
}

int Employee::countProjects() const {
    if (projects == nullptr)
        return 0;
    int projectCount = 0;
    while (projects[projectCount] != nullptr)
        projectCount++;
    return projectCount;
}

void Employee::presentEmployee() {
    cout << "Employee " << firstName << " " << Utils::capitalizeFirstLetter(lastName)
         << " has " << age << " years old and works in department " << department->getName() << endl;
}
