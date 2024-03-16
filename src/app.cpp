#include "employee.h"
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

using namespace std;

void showConstantsDataFromArrays() {
    cout << "Imiona:" << endl;
    for (string_view firstName : firstNames)
        cout << firstName << endl;
    cout << endl
         << "Nazwiska:" << endl;
    for (string_view lastName : lastNames)
        cout << lastName << endl;
}

void displayEmployeeInfo(const Employee &employee) {
    cout << "Employee " << employee.firstName << " " << capitalizeFirstLetter(employee.lastName) << " has "
         << employee.age << " years old and works in department " << employee.department.name << endl;
}

void create(Employee *&employee) {
    employee = new Employee;
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

void deleteEmployee(Employee *&employee) {
    delete employee;
    employee = nullptr;
}

void add(Project *project, Employee *employee) {
    if (employee->projects == nullptr) {
        employee->projects = new Project *[1];
        employee->projects[0] = project;
    } else {
        int newSize = 0;
        while (employee->projects[newSize] != nullptr)
            newSize++;
        newSize++;
        Project **newProjects = new Project *[newSize];
        for (int i = 0; i < newSize - 1; ++i)
            newProjects[i] = employee->projects[i];
        newProjects[newSize - 1] = project;
        delete[] employee->projects;
        employee->projects = newProjects;
    }
}

void show(Employee *employee) {
    cout << "ID: " << employee->id << endl;
    cout << "Name: " << employee->name << endl;
    cout << "Age: " << employee->age << endl;
    cout << "First Name: " << employee->firstName << endl;
    cout << "Last Name: " << employee->lastName << endl;
    cout << "Worked Hours: " << employee->workedHours << endl;
    cout << "Salary per hour: " << employee->salaryPerHour << endl;
    cout << "Address: " << employee->address.street_address << ", " << employee->address.city << ", " << employee->address.postal_code << endl;
    cout << "Department: " << employee->department.name << " (ID: " << employee->department.department_id << ")" << endl;
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

int main() {
    bool running = true;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> idDistribution(1000, 9999);
    uniform_int_distribution<int> recordsSizeDistribution(50, 100);

    showConstantsDataFromArrays();
    vector<Employee*> employees;
    const int RECORDS_SIZE = recordsSizeDistribution(eng);
    string_view Rekordy[100];

    while (running) {
        cout << "Menu:" << endl;
        cout << "1. Stworz pracownika" << endl;
        cout << "2. Dodaj projekt pracownikowi" << endl;
        cout << "3. Pokaz informacje o pracowniku" << endl;
        cout << "4. Oblicz zarobki pracownika" << endl;
        cout << "5. Pokaz ilosc projektow pracownika" << endl;
        cout << "6. Zdanie o pracowniku" << endl;
        cout << "7. Wyjscie" << endl;
        cout << "Wybierz opcje: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee *employee = nullptr;
                int age, workedHours;
                double salaryPerHour;
                string name, firstName, lastName, street_address, city, postal_code, departmentName, projectName, projectDescription;

                int id = idDistribution(eng);

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
                cout << "Ulica: ";
                cin >> street_address;
                cout << "Miasto: ";
                cin >> city;
                cout << "Kod pocztowy: ";
                cin >> postal_code;
                cout << "Podaj nazwe departamentu: ";
                cin >> departmentName;
                cout << "Podaj nazwe projektu: ";
                cin >> projectName;
                cout << "Podaj opis projektu: ";
                cin >> projectDescription;

                Project *project1 = new Project{projectName, 1, projectDescription};
                Project **projects = new Project *[2];
                projects[0] = project1;
                projects[1] = nullptr;

                Address address{street_address, city, postal_code};
                Department department{departmentName, 1};

                initialize(employee, id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects);
                employees.push_back(employee);
                break;
            }
            case 2: {
                if (employees.empty())
                    cout << "Najpierw stworz pracownika!" << endl;
                else {
                    int employeeIndex;
                    cout << "Wybierz indeks pracownika: ";
                    cin >> employeeIndex;

                    if (employeeIndex < 0 || employeeIndex >= employees.size()) {
                        cout << "Niepoprawny indeks pracownika!" << endl;
                        break;
                    }

                    Employee *employee = employees[employeeIndex];
                    string projectName, projectDescription;
                    cout << "Podaj nazwe projektu: ";
                    cin >> projectName;
                    cout << "Podaj opis projektu: ";
                    cin >> projectDescription;

                    Project *newProject = new Project{projectName, countProjects(employee) + 1, projectDescription};
                    add(newProject, employee);
                }
                break;
            }
            case 3: {
                if (employees.empty())
                    cout << "Brak pracownikow do wyswietlenia!" << endl;
                else {
                    int employeeIndex;
                    cout << "Wybierz indeks pracownika: ";
                    cin >> employeeIndex;

                    if (employeeIndex < 0 || employeeIndex >= employees.size()) {
                        cout << "Niepoprawny indeks pracownika!" << endl;
                        break;
                    }

                    Employee *employee = employees[employeeIndex];
                    show(employee);
                }
                break;
            }
            case 4: {
                if (employees.empty())
                    cout << "Brak pracownikow do obliczenia zarobkow!" << endl;
                else {
                    int employeeIndex;
                    cout << "Wybierz indeks pracownika: ";
                    cin >> employeeIndex;

                    if (employeeIndex < 0 || employeeIndex >= employees.size()) {
                        cout << "Niepoprawny indeks pracownika!" << endl;
                        break;
                    }

                    Employee *employee = employees[employeeIndex];
                    double salary = calculateSalary(employee);
                    cout << "Zarobki pracownika: " << salary << endl;
                }
                break;
            }
            case 5: {
                if (employees.empty())
                    cout << "Brak pracownikow do wyswietlenia ilosci projektow!" << endl;
                else {
                    int employeeIndex;
                    cout << "Wybierz indeks pracownika: ";
                    cin >> employeeIndex;

                    if (employeeIndex < 0 || employeeIndex >= employees.size()) {
                        cout << "Niepoprawny indeks pracownika!" << endl;
                        break;
                    }

                    Employee *employee = employees[employeeIndex];
                    int projectsCount = countProjects(employee);
                    cout << "Ilosc projektow pracownika: " << projectsCount << endl;
                }
                break;
            }
            case 6: {
                if (employees.empty())
                    cout << "Brak pracownikow do wyswietlenia!" << endl;
                else {
                    int employeeIndex;
                    cout << "Wybierz indeks pracownika: ";
                    cin >> employeeIndex;

                    if (employeeIndex < 0 || employeeIndex >= employees.size()) {
                        cout << "Niepoprawny indeks pracownika!" << endl;
                        break;
                    }

                    Employee *employee = employees[employeeIndex];
                    displayEmployeeInfo(*employee);
                    int projectsCount = countProjects(employee);
                    cout << "Ilosc projektow pracownika: " << projectsCount << endl;
                    
                    string result = "Employee " + employee->firstName + " " + capitalizeFirstLetter(employee->lastName) + " has " + to_string(projectsCount) + " projects.";
                    Rekordy[employeeIndex] = string_view(result);
                }
                break;
            }
            case 7: {
                running = false;
                break;
            }
            default: {
                cout << "Niepoprawny wybor!" << endl;
                break;
            }
        }
    }

    for (Employee *employee : employees)
        deleteEmployee(employee);
    
    return 0;
}
