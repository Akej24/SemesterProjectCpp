#ifndef PROJECT
#define PROJECT

#include <functional>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Project final {
private:
    string name;
    int projectId;
    string description;

public:
    Project(string name, int projectId, string description) : name(name), projectId(projectId), description(description) {}
    ~Project();
    string getName() const { return name; }
    int getProjectId() const { return projectId; }
    string getDescription() const { return description; }
    bool operator==(const string &projectName) const;
    friend istream &operator>>(istream &is, shared_ptr<Project> &project);
};

#endif