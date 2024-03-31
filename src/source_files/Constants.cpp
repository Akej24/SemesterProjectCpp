#include "../header_files/Constants.hpp"

void Constants::showHardcodedEmployees() {
    cout << "Imiona:\n";
    for (string_view firstName : firstNames)
        cout << firstName << "\n";

    cout << "\nNazwiska:\n";
    for (string_view lastName : lastNames)
        cout << lastName << "\n";
        
    cout << endl;
}