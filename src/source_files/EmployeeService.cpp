#include "../header_files/EmployeeService.hpp"

void EmployeeService::createEmployee(vector<Person *> &people, int id, bool withProject) {
    int age, workedHours;
    double salaryPerHour;
    string name, firstName, lastName, street_address, city, postal_code, departmentName, projectName, projectDescription;

    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    name = firstName + " " + lastName;
    cout << "Podaj wiek: ";
    cin >> age;
    cout << "Podaj liczbe przepracowanych godzin: ";
    cin >> workedHours;
    cout << "Podaj stawke godzinowa: ";
    cin >> salaryPerHour;
    cout << "Podaj adres:\n";
    cout << "a) Ulica: ";
    cin >> street_address;
    cout << "b) Miasto: ";
    cin >> city;
    cout << "c) Kod pocztowy: ";
    cin >> postal_code;
    cout << "Podaj nazwe oddzialu: ";
    cin >> departmentName;

    Address *address = new Address(street_address, city, postal_code);
    Department *department = new Department(departmentName, (int)people.size());

    if (withProject) {
        cout << "Podaj projekt: " << endl;
        cout << "a) Nazwa: ";
        cin >> projectName;
        cout << "b) Opis: ";
        cin >> projectDescription;

        Project *newProject = new Project(projectName, 1, projectDescription);
        EmployeeInitializationDataWithProject data(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, {newProject});
        people.push_back(new Employee(data));
    } else {
        EmployeeInitializationData data(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department);
        people.push_back(new Employee(data));
    }
}

void EmployeeService::deleteEmployeeFromVector(vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    delete dynamic_cast<Employee *>(people[personIndex]);
    people.erase(people.begin() + personIndex);
}

void EmployeeService::addProjectToEmployee(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName, projectDescription;
    cout << "Podaj nazwe projektu: ";
    cin >> projectName;
    cout << "Podaj opis projektu: ";
    cin >> projectDescription;

    auto *employee = dynamic_cast<Employee *>(people[personIndex]);
    Project *newProject = new Project{projectName, employee->countProjects() + 1, projectDescription};
    employee->addProject(*newProject);
}

void EmployeeService::deleteEmployeeProject(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName;
    cout << "Podaj nazwe projektu do usuniecia: ";
    cin >> projectName;

    auto *employee = dynamic_cast<Employee *>(people[personIndex]);
    employee->deleteProject(projectName);
}

void EmployeeService::calculateEmployeeSalary(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    double salary = dynamic_cast<Employee *>(people[personIndex])->calculateSalary();
    cout << "Zarobki pracownika: " << salary << endl;
}

void EmployeeService::showEmployeeProjectsAmount(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    int projectAmount = dynamic_cast<Employee *>(people[personIndex])->countProjects();
    cout << "Ilosc projektow pracownika: " << projectAmount << endl;
}

void EmployeeService::generateEmployeePresentation(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    dynamic_cast<Employee *>(people[personIndex])->presentEmployee();
}

void EmployeeService::cloneEmployee(vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto *employee = dynamic_cast<Employee *>(people[personIndex]);
    people.push_back(new Employee(*employee));
}

void EmployeeService::addLanguageToEmployee(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto *employee = dynamic_cast<Employee *>(people[personIndex]);

    string language;
    cout << "Enter programming language to add: ";
    cin >> language;
    employee->programmingLanguages.addLanguage(language);
}

void EmployeeService::removeLanguageFromEmployee(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto *employee = dynamic_cast<Employee *>(people[personIndex]);

    string language;
    cout << "Enter programming language to remove: ";
    cin >> language;
    if (employee->programmingLanguages.containsString(language))
        employee->programmingLanguages.removeLanguage(language);
}

void EmployeeService::showEmployeeLanguages(const vector<Person *> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto *employee = dynamic_cast<Employee *>(people[personIndex]);

    employee->programmingLanguages.showLanguagesAlphabetic();
}