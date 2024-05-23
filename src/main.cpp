#include "./header_files/BossService.hpp"
#include "./header_files/Constants.hpp"
#include "./header_files/EmployeeService.hpp"
#include "./header_files/PersonService.hpp"
#include "./header_files/ExampleCompany.hpp"
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
            << "[PRACOWNICY]\n"
            << "1. Stworz pracownika z projektem\n"
            << "2. Stworz pracownika bez projektu\n"
            << "3. Dodaj projekt pracownikowi\n"
            << "4. Usun projekt pracownikowi\n"
            << "5. Usun parcownika\n"
            << "6. Oblicz zarobki pracownika\n"
            << "7. Pokaz ilosc projektow pracownika\n"
            << "8. Zaprezentuj pracownika\n"
            << "9. Pokaz zahardcodowanych pracownikow\n"
            << "\n"
            << "[SZEFOWIE]\n"
            << "10. Stworz szefa\n"
            << "11. Usun szefa\n"
            << "12. Nadaj podwyzke jako szef\n"
            << "\n"
            << "[OSOBY]\n"
            << "13. Pokaz informacje o osobie\n"
            << "14. Zmodyfikuj adres osoby\n"
            << "15. Wygeneruj zdanie o osobie i zapisz do rekordow\n"
            << "16. Wyodredbnij (sparsuj) dane z rekordow o osobie\n"
            << "\n"
            << "17. Zademonstruj przeciazenie operatorow =,[],<< na przykladzie Firmy\n"
            << "18. Wyjscie\n"
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
            EmployeeService::deleteEmployeeFromVector(people);
            break;
        case 6:
            EmployeeService::calculateEmployeeSalary(people);
            break;
        case 7:
            EmployeeService::showEmployeeProjectsAmount(people);
            break;
        case 8:
            EmployeeService::generateEmployeePresentation(people);
            break;
        case 9:
            Constants::showHardcodedEmployees();
            break;
        case 10:
            BossService::createBoss(people, idDistribution(eng));
            break;
        case 11:
            BossService::deleteBossFromVector(people);
            break;
        case 12:
            BossService::giveRaise(people);
            break;
        case 13:
            Records::extractAttributesFromRecords(records, recordsSize);
            break;
        case 14:
            PersonService::showPersonInfo(people);
            break;
        case 15:
            PersonService::updateAddress(people);
            break;
        case 16:
            PersonService::savePersonToRecords(people, records);
            break;
        case 17:
            ExampleCompany::example();
            break;
        case 18:
            running = false;
            break;
        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }
    return 0;
}
