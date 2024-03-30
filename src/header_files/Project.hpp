#ifndef PROJECT
#define PROJECT

#include <string>

using namespace std;

class Project {
private:
    string name;
    int projectId;
    string description;

public:
    Project(string name, int projectId, string description)
        : name(name), projectId(projectId), description(description) {}

    string getCity() const { return name; }
    int getStreetAddress() const { return projectId; }
    string getPostalCode() const { return description; }
};

#endif