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
            << "1. Stworz pracownika\n"
            << "2. Dodaj projekt pracownikowi\n"
            << "3. Pokaz informacje o pracowniku\n"
            << "4. Oblicz zarobki pracownika\n"
            << "5. Pokaz ilosc projektow pracownika\n"
            << "6. Zaprezentuj pracownika\n"
            << "7. Pokaz zahardcodowanych pracownikow\n"
            << "8. Wygeneruj zdanie o pracownikow i zapisz do rekordow\n"
            << "9. Wyodredbnij (sparsuj) dane z rekordow\n"
            << "10. Wyjscie\n"
            << "--------------------------------------------------------" << endl;


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
