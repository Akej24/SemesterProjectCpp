#include "../header_files/ExampleCompany.hpp"

ExampleCompany::ExampleCompany() : employees {
    Employee(EmployeeInitializationDataWithProject(1, "John Doe", 30, "John", "Doe", 159, 22.84, 
        new Address("Address1", "City1", "12-123"), 
        new Department("Department1", 1), 
        {new Project("TestProject1", 1, "TestOpis1")})),

    Employee(EmployeeInitializationDataWithProject(2, "Jane Smith", 25, "Jane", "Smith", 150, 19.43, 
        new Address("Address2", "City2", "12-123"), 
        new Department("Department2", 2),
        {new Project("TestProject2", 2, "TestOpis2")})),

    Employee(EmployeeInitializationDataWithProject(3, "Alice Johnson", 35, "Alice", "Johnson", 168, 28.43, 
        new Address("Address3", "City3", "12-123"), 
        new Department("Department3", 3),
        {new Project("TestProject3", 3, "TestOpis3")})),
} { }

void ExampleCompany::example() {
    cout << "-------------------------------------------" << endl;
    cout << "Przyklad uzycia przeciazonego operatora []" << endl;
    for (int i = 0; i < 3; i++)
        cout << employees[i][0]->getName() << endl;

    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora <<]" << endl;
    cout << "Informacje o pracowniku 1:\n" << employees[0] << endl;
    cout << "Informacje o pracowniku 2:\n" << employees[1] << endl;

    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora =]" << endl;
    employees[1] = employees[0];
    cout << "Informacje o pracowniku 2 po przypisaniu:\n" << employees[1] << endl;
}