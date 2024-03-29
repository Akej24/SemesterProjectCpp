#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

void create(Employee *&employee) {
    employee = new Employee;
}

void deleteEmployee(Employee *&employee) {
    delete employee;
    employee = nullptr;
}

void initialize(Employee *&employee, int id, string name, int age, string firstName, string lastName, int workedHours, double salaryPerHour, Address address, Department department, Project **projects) {
    if (employee == nullptr)
        create(employee);

    employee->id = id;
    employee->name = name;
    employee->age = age;
    employee->firstName = firstName;
    employee->lastName = lastName;
    employee->workedHours = workedHours;
    employee->salaryPerHour = salaryPerHour;
    employee->address = address;
    employee->department = department;
    employee->projects = projects;
}

void add(Project *project, Employee *employee) {
    if (employee->projects == nullptr) {
        employee->projects = new Project *[2];
        employee->projects[0] = project;
        employee->projects[1] = nullptr;
    } else {
        int newSize = 0;
        while (employee->projects[newSize] != nullptr)
            newSize++;
        newSize++;
        Project **newProjects = new Project *[newSize + 1];
        for (int i = 0; i < newSize - 1; ++i)
            newProjects[i] = employee->projects[i];
        newProjects[newSize - 1] = project;
        newProjects[newSize] = nullptr;
        delete[] employee->projects;
        employee->projects = newProjects;
    }
}


void show(Employee *employee) {
    cout << "ID: " << employee->id << endl;
    cout << "Imie: " << employee->name << endl;
    cout << "Wiek: " << employee->age << endl;
    cout << "Imie: " << employee->firstName << endl;
    cout << "Nazwisko: " << employee->lastName << endl;
    cout << "Przepracowane godziny: " << employee->workedHours << endl;
    cout << "Pensja na godzine: " << employee->salaryPerHour << endl;
    cout << "Adres: " << employee->address.street_address << ", " << employee->address.city << ", " << employee->address.postal_code << endl;
    cout << "Oddzial: " << employee->department.name << " (ID: " << employee->department.department_id << ")" << endl;
}

double calculateSalary(Employee *employee) {
    return employee->workedHours * employee->salaryPerHour;
}

int countProjects(Employee *employee) {
    if (employee->projects == nullptr)
        return 0;
    int projectCount = 0;
    while (employee->projects[projectCount] != nullptr)
        projectCount++;
    return projectCount;
}

void showHardcodedEmployees() {
    cout << "Imiona:" << endl;
    for (string_view firstName : firstNames)
        cout << firstName << endl;
    cout << endl
         << "Nazwiska:" << endl;
    for (string_view lastName : lastNames)
        cout << lastName << endl;
}

void presentEmployee(const Employee &employee) {
    cout << "Employee " << employee.firstName << " " << capitalizeFirstLetter(employee.lastName) << " has "
         << employee.age << " years old and works in department " << employee.department.name << endl;
}

string capitalizeFirstLetter(const string &s) {
    if (s.empty())
        return "";
    string result = s;
    result[0] = toupper(result[0]);
    return result;
}
