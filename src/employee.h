#ifndef EMPLOYEE_STRUCTS_H
#define EMPLOYEE_STRUCTS_H

#include <string>

using namespace std;

constexpr string_view firstNames[] = {"John", "Alice", "Michael", "Emma", "William", "Olivia", "James", "Sophia", "Benjamin", "Isabella"};
constexpr string_view lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};

struct Address {
    string street_address;
    string city;
    string postal_code;
};

struct Department {
    string name;
    int department_id;
};

struct Project {
    string name;
    int project_id;
    string description;
};

struct Employee {
    int id;
    string name;
    int age;
    string firstName;
    string lastName;
    int workedHours;
    double salaryPerHour;
    Address address;
    Department department;
    Project **projects;
};

string capitalizeFirstLetter(const string &s);

#endif /* EMPLOYEE_STRUCTS_H */
