#include "../header_files/Validator.hpp"

bool checkValidEmployeeIndex(int employeeIndex, int employeesSize) {
    if (employeeIndex >= 0 && employeeIndex < employeesSize)
        return true;
    else {
        cout << "Niepoprawny indeks pracownika!" << endl;
        return false;
    }
}

bool checkAnyEmployeeExists(const vector<Employee *> &employees) {
    if (employees.empty()) {
        cout << "Brak pracownikow do wyswietlenia ilosci projektow!" << endl;
        return false;
    } else
        return true;
}