#include "employee.h"
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

using namespace std;

bool checkValidEmployeeIndex(int employeeIndex, const vector<Employee *> &employees) {
    if (employeeIndex >= 0 && employeeIndex < employees.size())
        return true;
    else {
        cout << "Niepoprawny indeks pracownika!" << endl;
        return false;
    }
}

bool checkAnyEmployeeExists(const vector<Employee *> &employees) {
    if (employees.empty()) {
        cout << "Brak pracownikow do wyswietlenia ilosci projektow!" << endl;
        return false;
    } else
        return true;
}

void createEmployee(vector<Employee *> &employees, int id) {
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

    cout << "Podaj projekt: " << endl;
    cout << "a) Nazwa ";
    cin >> projectName;
    cout << "b) Opis ";
    cin >> projectDescription;

    Project *project1 = new Project{projectName, 1, projectDescription};
    Project **projects = new Project *[2];
    projects[0] = project1;
    projects[1] = nullptr;

    Address address{street_address, city, postal_code};
    Department department{departmentName, 1};

    initialize(employee, id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects);
    employees.push_back(employee);
}

void addProjectToEmployee(const vector<Employee *> &employees) {
    if (!checkAnyEmployeeExists)
        return;

    int employeeIndex;
    cout << "Wybierz indeks pracownika: ";
    cin >> employeeIndex;
    if (!checkValidEmployeeIndex(employeeIndex, employees))
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
    if (!checkValidEmployeeIndex(employeeIndex, employees))
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
    if (!checkValidEmployeeIndex(employeeIndex, employees))
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
    if (!checkValidEmployeeIndex(employeeIndex, employees))
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
    if (!checkValidEmployeeIndex(employeeIndex, employees))
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
    if (!checkValidEmployeeIndex(employeeIndex, employees))
        return;

    Employee *employee = employees[employeeIndex];
    string resultSentence = "Employee " + employee->firstName + " " + capitalizeFirstLetter(employee->lastName) + " has " + to_string(countProjects(employee)) + " projects.";
    records[employeeIndex] = resultSentence;

    cout << "Pomyslnie zapisano, aktualne rekordy: " << endl;

    for (int i = 0; i < employees.size(); i++)
        if (!records[i].empty())
            cout << "Rekord " << i << ": " << records[i] << endl;
}

string extractFirstName(const string &sentence) {
    size_t start = sentence.find("Employee ") + 9;
    size_t end = sentence.find(" ", start);
    return sentence.substr(start, end - start);
}

string extractLastName(const string &sentence) {
    size_t start = sentence.find(" ") + 1;
    size_t end = sentence.find(" has ", start);
    return sentence.substr(start, end - start);
}

int extractProjectsAmount(const string &sentence) {
    size_t start = sentence.find(" has ") + 5;
    size_t end = sentence.find(" projects", start);
    return stoi(sentence.substr(start, end - start));
}

void extractAttributesFromRecords(const string *records, int size) {
    for (int i = 0; i < size; ++i) {
        if (!records[i].empty()) {
            string firstName = extractFirstName(records[i]);
            string lastName = extractLastName(records[i]);
            int projectsAmount = extractProjectsAmount(records[i]);
            cout << "Wyodrebnione dane: " << endl;
            cout << "- firstName: " << firstName << endl;
            cout << "- lastName: " << lastName << endl;
            cout << "- projectsAmount: " << projectsAmount << endl;
        }
    }
}