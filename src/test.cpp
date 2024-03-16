#include <iostream>
#include <string>
#include <random>

using namespace std;

constexpr std::string_view firstNames[] = {"John", "Alice", "Michael", "Emma", "William", "Olivia", "James", "Sophia", "Benjamin", "Isabella"};
constexpr std::string_view lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};

struct Address {
    string street_address;
    string city;
    string postal_code;
};

struct Department {
    string name;
    int department_id;
};

struct Project {
    string name;
    int project_id;
    string description;
};

struct Employee {
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    int workedHours;
    double salaryPerHour;
    Address address;
    Department department;
    Project **projects;
};

string capitalizeFirstLetter(const string &s) {
    if (s.empty())
        return "";

    string result = s;
    result[0] = toupper(result[0]); // Capitalize first letter
    return result;
}

void showConstantsDataFromArrays() {
    cout << "Imiona:" << endl;
    for (std::string_view firstName : firstNames) {
        cout << firstName << endl;
    }

    cout << endl
         << "Nazwiska:" << endl;
    for (std::string_view lastName : lastNames)
    {
        cout << lastName << endl;
    }
}

void displayEmployeeInfo(const Employee &employee) {
    cout << "Employee " << employee.firstName << " " << capitalizeFirstLetter(employee.lastName) << " has "
         << employee.age << " years old and works in department " << employee.department.name << endl;
}

void create(Employee *&employee) {
    employee = new Employee;
}

void initialize(Employee *&employee, int id, string name, int age, string firstName, string lastName, int workedHours, double salaryPerHour, Address address, Department department, Project **projects) {
    if (employee == nullptr) create(employee);

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
    }
    else {
        int newSize = 0;
        while (employee->projects[newSize] != nullptr) {
            newSize++;
        }
        newSize++;
        Project **newProjects = new Project *[newSize];
        for (int i = 0; i < newSize - 1; ++i) {
            newProjects[i] = employee->projects[i];
        }
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
    if (employee->projects == nullptr) return 0;
    int projectCount = 0;
    while (employee->projects[projectCount] != nullptr) projectCount++;
    return projectCount;
}

int main() {
    Employee *employee = nullptr;
    bool running = true;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> idDistribution(1000, 9999);

    showConstantsDataFromArrays();
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
                break;
            }
            case 2: {
                if (employee != nullptr) {
                    string projectName, projectDescription;
                    cout << "Podaj nazwe projektu: ";
                    cin >> projectName;
                    cout << "Podaj opis projektu: ";
                    cin >> projectDescription;

                    Project *newProject = new Project{projectName, countProjects(employee) + 1, projectDescription};
                    add(newProject, employee);
                } else cout << "Najpierw stworz pracownika!" << endl;
                break;
            }
            case 3: {
                if (employee != nullptr) {
                    show(employee);
                } else cout << "Brak pracownika do wyswietlenia!" << endl;
                break;
            }
            case 4: {
                if (employee != nullptr) {
                    double salary = calculateSalary(employee);
                    cout << "Zarobki pracownika: " << salary << endl;
                } else cout << "Brak pracownika do obliczenia zarobkow!" << endl;
                break;
            }
            case 5: {
                if (employee != nullptr) {
                    int projectsCount = countProjects(employee);
                    cout << "Ilosc projektow pracownika: " << projectsCount << endl;
                } else cout << "Brak pracownika do wyswietlenia ilosci projektow!" << endl;
                break;
            }
            case 6: {
                if (employee != nullptr) {
                    displayEmployeeInfo(*employee);
                    int projectsCount = countProjects(employee);
                    cout << "Ilosc projektow pracownika: " << projectsCount << endl;
                } else cout << "Brak pracownika do wyswietlenia!" << endl;
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
    if (employee != nullptr) deleteEmployee(employee);
    return 0;
}
