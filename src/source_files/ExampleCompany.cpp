#include "../header_files/ExampleCompany.hpp"

void ExampleCompany::example() {
    cout << "-------------------------------------------" << endl;
    cout << "Przyklad uzycia przeciazonego operatora []" << endl;
    for (int i = 0; i < 3; i++)
        cout << employees[i][0]->getName() << endl;

    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora <<]" << endl;
    cout << "Informacje o pracowniku 1:\n" << employees[0] << endl;
    cout << "Informacje o pracowniku 2:\n" << employees[1] << endl;

    cout << "-------------------------------------------" << endl;
    cout << "[Przyklad uzycia przeciazonego operatora =]" << endl;
    employees[1] = employees[0];
    cout << "Informacje o pracowniku 2 po przypisaniu:\n" << employees[1] << endl;
}