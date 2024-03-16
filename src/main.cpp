#include "choiceService.h"
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

using namespace std;

int main() {
    bool running = true;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> idDistribution(1000, 9999);
    uniform_int_distribution<int> recordsSizeDistribution(50, 100);

    vector<Employee *> employees;
    const int recordsSize = recordsSizeDistribution(eng);
    string *records = new string[recordsSize];

    while (running) {
        cout << "--------------------------------------------------------" << endl;
        cout << "1. Stworz pracownika" << endl;
        cout << "2. Dodaj projekt pracownikowi" << endl;
        cout << "3. Pokaz informacje o pracowniku" << endl;
        cout << "4. Oblicz zarobki pracownika" << endl;
        cout << "5. Pokaz ilosc projektow pracownika" << endl;
        cout << "6. Zaprezentuj pracownika" << endl;
        cout << "7. Pokaz zahardcodowanych pracownikow" << endl;
        cout << "8. Wygeneruj zdanie o pracownikow i zapisz do rekordow" << endl;
        cout << "9. Wyodredbnij (sparsuj) dane z rekordow" << endl;
        cout << "10. Wyjscie" << endl;
        cout << "--------------------------------------------------------" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            createEmployee(employees, idDistribution(eng));
            break;
        case 2:
            addProjectToEmployee(employees);
            break;
        case 3:
            showEmployeeInfo(employees);
            break;
        case 4:
            calculateEmployeeSalary(employees);
            break;
        case 5:
            showEmployeeProjectsAmount(employees);
            break;
        case 6:
            generateEmployeePresentation(employees);
            break;
        case 7:
            showHardcodedEmployees();
            break;
        case 8:
            saveEmployeeProjectsSentenceToRecords(employees, records);
            break;
        case 9:
            extractAttributesFromRecords(records, recordsSize);
            break;
        case 10:

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
