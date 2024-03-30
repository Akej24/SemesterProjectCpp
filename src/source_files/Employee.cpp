#include "../header_files/Employee.hpp"

void create(Employee *&employee) {
    employee = new Employee;
}

/*
    Employee *employee: Passing by value. Changes to the pointer (like setting it to nullptr) won't affect the original pointer outside the function, but changes to the
    object pointed to by the pointer (like deleting it) will. Employee *&employee: Passing by reference. Changes to the pointer (like setting it to nullptr) will affect
    the original pointer outside the function, as well as changes to the object pointed to by the pointer.
*/

void deleteEmployee(Employee *&employee) { // if I use * it will delete only copy of pointer, when I use *& it will delete by reference instead of value
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
    cout << "ID: " << employee->id << "\n";
    cout << "Imie: " << employee->name << "\n";
    cout << "Wiek: " << employee->age << "\n";
    cout << "Imie: " << employee->firstName << "\n";
    cout << "Nazwisko: " << employee->lastName << "\n";
    cout << "Przepracowane godziny: " << employee->workedHours << "\n";
    cout << "Pensja na godzine: " << employee->salaryPerHour << "\n";
    cout << "Adres: " << employee->address.street_address << ", " << employee->address.city << ", " << employee->address.postal_code << "\n";
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

void presentEmployee(const Employee &employee) {
    cout << "Employee " << employee.firstName << " " << capitalizeFirstLetter(employee.lastName)
        << " has " << employee.age << " years old and works in department " << employee.department.name << endl;
}
