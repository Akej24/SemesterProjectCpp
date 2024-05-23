#include "./header_files/PersonService.hpp"
#include "./header_files/EmployeeService.hpp"
#include "./header_files/BossService.hpp"
#include "./header_files/Constants.hpp"
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

using namespace std;

int main() {
    bool running = true;

    default_random_engine eng(random_device{}());
    uniform_int_distribution<int> idDistribution(1000, 9999);
    uniform_int_distribution<int> recordsSizeDistribution(50, 100);

    const int recordsSize = recordsSizeDistribution(eng);

    string *records = new string[recordsSize];
    vector<Person *> people;

    while (running) {
        cout
            << "--------------------------------------------------------\n"
            << "1. Stworz pracownika z projektem\n"
            << "2. Stworz pracownika bez projektu\n"
            << "3. Dodaj projekt pracownikowi\n"
            << "4. Usun projekt pracownikowi\n"
            << "5. Pokaz informacje o osobach\n"
            << "6. Usun parcownika\n"
            << "7. Oblicz zarobki pracownika\n"
            << "8. Pokaz ilosc projektow pracownika\n"
            << "9. Zaprezentuj pracownika\n"
            << "10. Pokaz zahardcodowanych pracownikow\n"
            << "11. Wygeneruj zdanie o pracownikow i zapisz do rekordow\n"
            << "12. Wyodredbnij (sparsuj) dane z rekordow\n"
            << "13. Stworz szefa\n"
            << "14. Usun szefa\n"
            << "15. Nadaj podwyzke jako szef\n"
            << "16. Zmodyfikuj adres\n"
            << "17. Wyjscie\n"
            << "--------------------------------------------------------" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            EmployeeService::createEmployee(people, idDistribution(eng), true);
            break;
        case 2:
            EmployeeService::createEmployee(people, idDistribution(eng), false);
            break;
        case 3:
            EmployeeService::addProjectToEmployee(people);
            break;
        case 4:
            EmployeeService::deleteEmployeeProject(people);
            break;
        case 5:
            PersonService::showPersonInfo(people);
            break;
        case 6:
            EmployeeService::deleteEmployeeFromVector(people);
            break;
        case 7:
            EmployeeService::calculateEmployeeSalary(people);
            break;
        case 8:
            EmployeeService::showEmployeeProjectsAmount(people);
            break;
        case 9:
            EmployeeService::generateEmployeePresentation(people);
            break;
        case 10:
            Constants::showHardcodedEmployees();
            break;
        case 11:
            PersonService::saveEmployeeProjectsSentenceToRecords(people, records);
            break;
        case 12:
            Records::extractAttributesFromRecords(records, recordsSize);
            break;
        case 13:
            BossService::createBoss(people, idDistribution(eng));
            break;
        case 14:
            BossService::deleteBossFromVector(people);
            break;
        case 15:
            BossService::giveRaise(people);
            break;        
        case 16:
            PersonService::updateAddress(people);
            break;
        case 17:
            running = false;
            break;
        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }
    return 0;
}
