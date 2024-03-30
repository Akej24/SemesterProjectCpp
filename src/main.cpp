#include <iostream>
#include <random>
#include <string_view>
#include <vector>
#include "./header_files/ChoiceService.hpp"
#include "./header_files/Constants.hpp"

using namespace std;

int main() {
    bool running = true;

    default_random_engine eng(random_device{}());
    uniform_int_distribution<int> idDistribution(1000, 9999);
    uniform_int_distribution<int> recordsSizeDistribution(50, 100);

    const int recordsSize = recordsSizeDistribution(eng);
    string *records = new string[recordsSize];
    vector<Employee *> employees;

    while (running) {
        cout 
            << "--------------------------------------------------------\n"
            << "1. Stworz pracownika z projektem\n"
            << "2. Stworz pracownika bez projektu\n"
            << "3. Dodaj projekt pracownikowi\n"
            << "4. Pokaz informacje o pracowniku\n"
            << "5. Usun parcownika\n"
            << "6. Oblicz zarobki pracownika\n"
            << "7. Pokaz ilosc projektow pracownika\n"
            << "8. Zaprezentuj pracownika\n"
            << "9. Pokaz zahardcodowanych pracownikow\n"
            << "10. Wygeneruj zdanie o pracownikow i zapisz do rekordow\n"
            << "11. Wyodredbnij (sparsuj) dane z rekordow\n"
            << "12. Wyjscie\n"
            << "--------------------------------------------------------" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            createEmployee(employees, idDistribution(eng), true);
            break;
        case 2:
            createEmployee(employees, idDistribution(eng), false);
            break;
        case 3:
            addProjectToEmployee(employees);
            break;
        case 4:
            showEmployeeInfo(employees);
            break;
        case 5:
            deleteEmployeeFromVector(employees);
            break;
        case 6:
            calculateEmployeeSalary(employees);
            break;
        case 7:
            showEmployeeProjectsAmount(employees);
            break;
        case 8:
            generateEmployeePresentation(employees);
            break;
        case 9:
            showHardcodedEmployees();
            break;
        case 10:
            saveEmployeeProjectsSentenceToRecords(employees, records);
            break;
        case 11:
            extractAttributesFromRecords(records, recordsSize);
            break;
        case 12:
            running = false;
            break;
        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }

    for (Employee *employee : employees)
        deleteEmployee(employee);

    delete[] records;

    return 0;
}
