#include "../header_files/Constants.hpp"

static constexpr string_view firstNames[] = {"John", "Alice", "Michael", "Emma", "William", "Olivia", "James", "Sophia", "Benjamin", "Isabella"};
static constexpr string_view lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};

void Constants::showHardcodedEmployees() {
    cout << "Imiona:\n";
    for (string_view firstName : firstNames)
        cout << firstName << "\n";

    cout << "\nNazwiska:\n";
    for (string_view lastName : lastNames)
        cout << lastName << "\n";
        
    cout << endl;
}