#ifndef PROJECT
#define PROJECT

#include <functional>
#include <string>

using namespace std;

class Project final {
private:
    string name;
    int projectId;
    string description;

public:
    Project(string name, int projectId, string description) : name(name), projectId(projectId), description(description) {}
    ~Project() { cout << "Projekt o id: " << projectId << ", nazwie: " << name << " zostal usuniety" << endl; }
    string getName() const { return name; }
    int getProjectId() const { return projectId; }
    string getDescription() const { return description; }
    bool operator==(const string &projectName) const { return this->name == projectName; }
};

#endif