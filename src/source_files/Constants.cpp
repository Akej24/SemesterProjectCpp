#include "../header_files/Constants.hpp"

void showHardcodedEmployees() {
    cout << "Imiona:\n";
    for (string_view firstName : firstNames)
        cout << firstName << "\n";

    cout << "\nNazwiska:\n";
    for (string_view lastName : lastNames)
        cout << lastName << "\n";
        
    cout << endl;
}