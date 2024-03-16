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

void create(Employee *&employee);
void initialize(Employee *&employee, int id, string name, int age, string firstName, string lastName, int workedHours, double salaryPerHour, Address address, Department department, Project **projects);
void deleteEmployee(Employee *&employee);
void add(Project *project, Employee *employee);
void show(Employee *employee);

double calculateSalary(Employee *employee);
int countProjects(Employee *employee);

void showHardcodedEmployees();

string capitalizeFirstLetter(const string &s);
void presentEmployee(const Employee &employee);