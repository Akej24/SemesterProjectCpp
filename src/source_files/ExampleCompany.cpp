#include "../header_files/ExampleCompany.hpp"

Employee *ExampleCompany::employees = nullptr;

void ExampleCompany::initEmployees() {
    employees = new Employee[3]{
        Employee(EmployeeInitializationData(1, "John Doe", 30, "John", "Doe", 159, 22.84, new Address("Address1", "City1", "12-123"), new Department("Department1", 1))),
        Employee(EmployeeInitializationData(2, "Jane Smith", 25, "Jane", "Smith", 150, 19.43, new Address("Address2", "City2", "12-123"), new Department("Department2", 2))),
        Employee(EmployeeInitializationData(3, "Alice Johnson", 35, "Alice", "Johnson", 168, 28.43, new Address("Address3", "City3", "12-123"), new Department("Department3", 3)))};
}

void ExampleCompany::example() {
    ExampleCompany::initEmployees();
    Employee *employee1 = &employees[0];
    Employee *employee2 = &employees[1];

    cout << "-------------------------------------------" << endl;
    cout << "Przyklad uzycia przeciazonego operatora []" << endl;
    for (int i = 0; i < 3; i++)
            cout << employees[i] << endl;

    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora <<]" << endl;
    cout << "Informacje o pracowniku 1:\n" << *employee1 << endl;
    cout << "Informacje o pracowniku 2:\n" << *employee2 << endl;

    
    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora =]" << endl;
    employee2 = employee1;
    cout << "Informacje o pracowniku 2 po przypisaniu:\n" << *employee2 << endl;

    delete[] ExampleCompany::employees;
}