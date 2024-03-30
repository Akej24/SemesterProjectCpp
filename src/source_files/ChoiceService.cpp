#include "../header_files/ChoiceService.hpp"

void createEmployee(vector<Employee *> &employees, int id, bool withProject) {
    Employee *employee = nullptr;
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

    cout << "Podaj adres:" << endl;
    cout << "a) Ulica: ";
    cin >> street_address;
    cout << "b) Miasto: ";
    cin >> city;
    cout << "c) Kod pocztowy: ";
    cin >> postal_code;

    cout << "Podaj nazwe oddzialu: ";
    cin >> departmentName;

    Address address{street_address, city, postal_code};
    Department department{departmentName, (int) employees.size()};

    if(withProject) {
        cout << "Podaj projekt: " << endl;
        cout << "a) Nazwa ";
        cin >> projectName;
        cout << "b) Opis ";
        cin >> projectDescription;

        Project *project1 = new Project{projectName, 1, projectDescription};
        Project **projects = new Project *[2]; // it indicates on array of pointers that each other is refering to specific project: projects -> [*project1->[projectData...],*project2->[projectData...],*project3->[projectData...],...]
        projects[0] = project1;
        projects[1] = nullptr;

        InitializationDataWithProject data(employee, id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects);
        initialize(data);
        employees.push_back(employee);
    } else {
        InitializationData data(employee, id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department);
        initialize(data);
        employees.push_back(employee);
    }
}

void deleteEmployeeFromVector(vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    deleteEmployee(employees[employeeIndex]);
    employees.erase(employees.begin() + employeeIndex);
}

void addProjectToEmployee(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    string projectName, projectDescription;
    cout << "Podaj nazwe projektu: ";
    cin >> projectName;
    cout << "Podaj opis projektu: ";
    cin >> projectDescription;

    Project *newProject = new Project{projectName, countProjects(employee) + 1, projectDescription};
    add(newProject, employee);
}

void showEmployeeInfo(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    show(employee);
}

void calculateEmployeeSalary(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    double salary = calculateSalary(employee);
    cout << "Zarobki pracownika: " << salary << endl;
}

void showEmployeeProjectsAmount(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    cout << "Ilosc projektow pracownika: " << countProjects(employee) << endl;
}

void generateEmployeePresentation(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    presentEmployee(*employee);
}

void saveEmployeeProjectsSentenceToRecords(const vector<Employee *> &employees, string *records) {
    if (!checkAnyEmployeeExists(employees))
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees.size()))
        return;

    Employee *employee = employees[employeeIndex];
    string resultSentence = "Employee " + employee->firstName + " " + capitalizeFirstLetter(employee->lastName) + " has " + to_string(countProjects(employee)) + " projects.";
    records[employeeIndex] = resultSentence;

    cout << "Pomyslnie zapisano, aktualne rekordy: " << endl;

    for (int i = 0; i < employees.size(); i++)
        if (!records[i].empty())
            cout << "Rekord " << i << ": " << records[i] << endl;
}