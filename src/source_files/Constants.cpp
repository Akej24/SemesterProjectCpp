#include "../header_files/Constants.hpp"

void showHardcodedEmployees() {
    cout << "Imiona:\n";
    for (string_view firstName : firstNames)
        cout << firstName << endl;

    cout << "\nNazwiska:\n";
    for (string_view lastName : lastNames)
        cout << lastName << endl;
}