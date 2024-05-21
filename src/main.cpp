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
            << "4. Usun projekt pracownikowi\n"
            << "5. Pokaz informacje o pracowniku\n"
            << "6. Usun parcownika\n"
            << "7. Oblicz zarobki pracownika\n"
            << "8. Pokaz ilosc projektow pracownika\n"
            << "9. Zaprezentuj pracownika\n"
            << "10. Pokaz zahardcodowanych pracownikow\n"
            << "11. Wygeneruj zdanie o pracownikow i zapisz do rekordow\n"
            << "12. Wyodredbnij (sparsuj) dane z rekordow\n"
            << "13. Wyjscie\n"
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
            deleteEmployeeProject(employees);
            break;
        case 5:
            showEmployeeInfo(employees);
            break;
        case 6:
            deleteEmployeeFromVector(employees);
            break;
        case 7:
            calculateEmployeeSalary(employees);
            break;
        case 8:
            showEmployeeProjectsAmount(employees);
            break;
        case 9:
            generateEmployeePresentation(employees);
            break;
        case 10:
            Constants::showHardcodedEmployees();
            break;
        case 11:
            saveEmployeeProjectsSentenceToRecords(employees, records);
            break;
        case 12:
            Records::extractAttributesFromRecords(records, recordsSize);
            break;
        case 13:
            running = false;
            break;
        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }
    return 0;
}
