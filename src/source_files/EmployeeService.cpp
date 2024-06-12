#include "../header_files/EmployeeService.hpp"

void EmployeeService::createEmployee(vector<shared_ptr<Person>> &people, int id, bool withProject) {
    int age, workedHours;
    double salaryPerHour;
    string name, firstName, lastName, departmentName, projectName, projectDescription;
    Address* address;
    Project* newProject;

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
    cin >> address;
    cout << "Podaj nazwe oddzialu: ";
    cin >> departmentName;
    unique_ptr<Department> department = make_unique<Department>(departmentName, (int)people.size());

    if (withProject) {
        cin >> newProject;
        vector<shared_ptr<Project>> projects = { make_shared<Project>(*newProject) };
        people.push_back(make_shared<Employee>(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, move(department), projects));
    } else {
        vector<shared_ptr<Project>> projects;
        people.push_back(make_shared<Employee>(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, move(department), projects));
    }
}

void EmployeeService::deleteEmployeeFromVector(vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    people[personIndex].reset();
    people.erase(people.begin() + personIndex);
}

void EmployeeService::addProjectToEmployee(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName, projectDescription;
    cout << "Podaj nazwe projektu: ";
    cin >> projectName;
    cout << "Podaj opis projektu: ";
    cin >> projectDescription;

    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    Project *newProject = new Project{projectName, employee.get()->countProjects() + 1, projectDescription};
    employee.get()->addProject(*newProject);
}

void EmployeeService::deleteEmployeeProject(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName;
    cout << "Podaj nazwe projektu do usuniecia: ";
    cin >> projectName;

    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    employee.get()->deleteProject(projectName);
}

void EmployeeService::calculateEmployeeSalary(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    double salary = dynamic_pointer_cast<Employee>(people[personIndex]).get()->calculateSalary();
    cout << "Zarobki pracownika: " << salary << endl;
}

void EmployeeService::showEmployeeProjectsAmount(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    int projectAmount = dynamic_pointer_cast<Employee>(people[personIndex]).get()->countProjects();
    cout << "Ilosc projektow pracownika: " << projectAmount << endl;
}

void EmployeeService::generateEmployeePresentation(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    dynamic_pointer_cast<Employee>(people[personIndex]).get()->presentEmployee();
}

void EmployeeService::cloneEmployee(vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    people.push_back(make_shared<Employee>(*employee));
}

void EmployeeService::addLanguageToEmployee(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    string language;
    cout << "Enter programming language to add: ";
    cin >> language;
    employee.get()->programmingLanguages.addLanguage(language);
}

void EmployeeService::removeLanguageFromEmployee(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    string language;
    cout << "Enter programming language to remove: ";
    cin >> language;
    if (employee.get()->programmingLanguages.containsString(language))
        employee.get()->programmingLanguages.removeLanguage(language);
}

void EmployeeService::showEmployeeLanguages(const vector<shared_ptr<Person>> &people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    employee.get()->programmingLanguages.showLanguagesAlphabetic();
}