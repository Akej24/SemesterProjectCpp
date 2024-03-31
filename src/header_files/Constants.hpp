#ifndef CONSTANTS
#define CONSTANTS

#include <iostream>
#include <string>

using namespace std;

class Constants {
private:
    static constexpr string_view firstNames[] = {"John", "Alice", "Michael", "Emma", "William", "Olivia", "James", "Sophia", "Benjamin", "Isabella"};
    static constexpr string_view lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};
    Constants();

public:
    static void showHardcodedEmployees();
};

#endif