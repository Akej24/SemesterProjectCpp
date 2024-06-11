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
    vector<shared_ptr<Person>> people;

    auto& personService = PersonService::getInstance();
    auto& employeeService = EmployeeService::getInstance();
    auto& bossService = BossService::getInstance();
    auto exampleCompany = new ExampleCompany();

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
            << "10. Sklonuj pracownika\n"
            << "\n"
            << "[PRACOWNICY - JEZYKI]\n"
            << "11. Dodaj jezyk pracownikowi\n"
            << "12. Usun jezyk pracownikowi\n"
            << "13. Pokaz jezyki pracownika alfabetycznie\n"
            << "\n"
            << "[SZEFOWIE]\n"
            << "14. Stworz szefa\n"
            << "15. Usun szefa\n"
            << "16. Nadaj podwyzke jako szef\n"
            << "\n"
            << "[OSOBY]\n"
            << "17. Pokaz informacje o osobie\n"
            << "18. Zmodyfikuj adres osoby\n"
            << "19. Wygeneruj zdanie o osobie i zapisz do rekordow\n"
            << "20. Wyodredbnij (sparsuj) dane z rekordow o osobie\n"
            << "\n"
            << "21. Zademonstruj przeciazenie operatorow =,[],<< na przykladzie Firmy\n"
            << "22. Wyjscie\n"
            << "--------------------------------------------------------" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            employeeService.createEmployee(people, idDistribution(eng), true);
            break;
        case 2:
            employeeService.createEmployee(people, idDistribution(eng), false);
            break;
        case 3:
            employeeService.addProjectToEmployee(people);
            break;
        case 4:
            employeeService.deleteEmployeeProject(people);
            break;
        case 5:
            employeeService.deleteEmployeeFromVector(people);
            break;
        case 6:
            employeeService.calculateEmployeeSalary(people);
            break;
        case 7:
            employeeService.showEmployeeProjectsAmount(people);
            break;
        case 8:
            employeeService.generateEmployeePresentation(people);
            break;
        case 9:
            Constants::showHardcodedEmployees();
            break;
        case 10:
            employeeService.cloneEmployee(people);
            break;
        case 11:
            employeeService.addLanguageToEmployee(people);
            break;
        case 12:
            employeeService.removeLanguageFromEmployee(people);
            break;
        case 13:
            employeeService.showEmployeeLanguages(people);
            break;
        case 14:
            bossService.createBoss(people, idDistribution(eng));
            break;
        case 15:
            bossService.deleteBossFromVector(people);
            break;
        case 16:
            bossService.giveRaise(people);
            break;
        case 17:
            personService.showPersonInfo(people);
            break;
        case 18:
            personService.updateAddress(people);
            break;
        case 19:
            personService.savePersonToRecords(people, records);
            break;
        case 20:
            Records::extractAttributesFromRecords(records, recordsSize);
            break;
        case 21:
            exampleCompany->example();
            break;
        case 22:
            running = false;
            break;
        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }
    return 0;
}
