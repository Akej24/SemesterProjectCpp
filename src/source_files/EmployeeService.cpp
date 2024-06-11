#include "../header_files/EmployeeService.hpp"

void EmployeeService::createEmployee(vector<shared_ptr<Person>>& people, int id, bool withProject) {
    int age, workedHours;
    double salaryPerHour;
    string name, firstName, lastName, departmentName, projectName, projectDescription;
    unique_ptr<Address> address;
    unique_ptr<Project> newProject;

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
    unique_ptr<Department> department = make_unique<Department>(departmentName, static_cast<int>(people.size()));

    if (withProject) {
        cin >> newProject;
        EmployeeInitializationDataWithProject data(id, name, age, firstName, lastName, workedHours, salaryPerHour, move(address), move(department), vector<unique_ptr<Project>>{move(newProject)});
        people.push_back(make_shared<Employee>(data));
    } else {
        EmployeeInitializationData data(id, name, age, firstName, lastName, workedHours, salaryPerHour, move(address), move(department));
        people.push_back(make_shared<Employee>(data));
    }
}

void EmployeeService::deleteEmployeeFromVector(vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    people.erase(people.begin() + personIndex);
}

void EmployeeService::addProjectToEmployee(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName, projectDescription;
    cout << "Podaj nazwe projektu: ";
    cin >> projectName;
    cout << "Podaj opis projektu: ";
    cin >> projectDescription;

    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    employee->addProject(make_unique<Project>(projectName, employee->countProjects() + 1, projectDescription));
}

void EmployeeService::deleteEmployeeProject(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;

    string projectName;
    cout << "Podaj nazwe projektu do usuniecia: ";
    cin >> projectName;

    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    employee->deleteProject(projectName);
}

void EmployeeService::calculateEmployeeSalary(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    double salary = dynamic_pointer_cast<Employee>(people[personIndex])->calculateSalary();
    cout << "Zarobki pracownika: " << salary << endl;
}

void EmployeeService::showEmployeeProjectsAmount(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    int projectAmount = dynamic_pointer_cast<Employee>(people[personIndex])->countProjects();
    cout << "Ilosc projektow pracownika: " << projectAmount << endl;
}

void EmployeeService::generateEmployeePresentation(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    dynamic_pointer_cast<Employee>(people[personIndex])->presentEmployee();
}

void EmployeeService::cloneEmployee(vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);
    people.push_back(make_shared<Employee>(*employee));
}

void EmployeeService::addLanguageToEmployee(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    string language;
    cout << "Enter programming language to add: ";
    cin >> language;
    employee->programmingLanguages.addLanguage(language);
}

void EmployeeService::removeLanguageFromEmployee(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    string language;
    cout << "Enter programming language to remove: ";
    cin >> language;
    if (employee->programmingLanguages.containsString(language))
        employee->programmingLanguages.removeLanguage(language);
}

void EmployeeService::showEmployeeLanguages(const vector<shared_ptr<Person>>& people) {
    int personIndex = ServiceHelper::handleGetEmployeeIndex(people);
    if (personIndex == -1)
        return;
    auto employee = dynamic_pointer_cast<Employee>(people[personIndex]);

    employee->programmingLanguages.showLanguagesAlphabetic();
}