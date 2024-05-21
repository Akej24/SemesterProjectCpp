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
    ~Project() {
        cout << "Projekt o id: " << projectId << ", nazwie: " << name << " zostal usuniety" << endl;
    }

    string getName() const { return name; }
    int getProjectId() const { return projectId; }
    string getDescription() const { return description; }
};

#endif