#include "../header_files/ChoiceService.hpp"

int handleGetEmployeeIndex(const vector<Employee *> &employees) {
    if (!Validator::checkAnyEmployeeExists)
        return -1;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!Validator::checkValidEmployeeIndex(employeeIndex, employees.size()))
        return -1;
    return employeeIndex;
}

void createEmployee(vector<Employee *> &employees, int id, bool withProject) {
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
    Department *department = new Department(departmentName, (int)employees.size());

    if (withProject) {
        cout << "Podaj projekt: " << endl;
        cout << "a) Nazwa ";
        cin >> projectName;
        cout << "b) Opis ";
        cin >> projectDescription;

        Project *project1 = new Project(projectName, 1, projectDescription);
        Project **projects = new Project *[2]; // it indicates on array of pointers that each other is refering to specific project: projects -> [*project1->[projectData...],*project2->[projectData...],*project3->[projectData...],...]
        projects[0] = project1;
        projects[1] = nullptr;

        InitializationDataWithProject data(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects);
        employees.push_back(new Employee(data));
    } else {
        InitializationData data(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department);
        employees.push_back(new Employee(data));
    }
}

void deleteEmployeeFromVector(vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;
    employees[employeeIndex]->deleteEmployee();
    employees.erase(employees.begin() + employeeIndex);
}

void addProjectToEmployee(const vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;

    string projectName, projectDescription;
    cout << "Podaj nazwe projektu: ";
    cin >> projectName;
    cout << "Podaj opis projektu: ";
    cin >> projectDescription;

    Employee *employee = employees[employeeIndex];
    Project *newProject = new Project{projectName, employee->countProjects() + 1, projectDescription};
    employee->addProject(newProject);
}

void showEmployeeInfo(const vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;
    employees[employeeIndex]->show();
}

void calculateEmployeeSalary(const vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;
    double salary = employees[employeeIndex]->calculateSalary();
    cout << "Zarobki pracownika: " << salary << endl;
}

void showEmployeeProjectsAmount(const vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;
    int projectAmount = employees[employeeIndex]->countProjects();
    cout << "Ilosc projektow pracownika: " << projectAmount << endl;
}

void generateEmployeePresentation(const vector<Employee *> &employees) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;
    Employee *employee = employees[employeeIndex];
    employee->presentEmployee();
}

void saveEmployeeProjectsSentenceToRecords(const vector<Employee *> &employees, string *records) {
    int employeeIndex = handleGetEmployeeIndex(employees);
    if (employeeIndex == -1)
        return;

    Employee *employee = employees[employeeIndex];
    string resultSentence = "Employee " + employee->getFirstName() + " " + Utils::capitalizeFirstLetter(employee->getLastName()) + " has " + to_string(employee->countProjects()) + " projects.";
    records[employeeIndex] = resultSentence;

    cout << "Pomyslnie zapisano, aktualne rekordy: " << endl;
    for (int i = 0; i < employees.size(); i++)
        if (!records[i].empty())
            cout << "Rekord " << i << ": " << records[i] << endl;
}