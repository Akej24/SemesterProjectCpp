#include "../header_files/Project.hpp"

Project::~Project() { 
    cout << "Projekt o id: " << projectId << ", nazwie: " << name << " zostal usuniety" << endl; 
}

bool Project::operator==(const string &projectName) const {
    return this->name == projectName;
}

istream &operator>>(istream &is, shared_ptr<Project> &project) {
    string projectName, projectDescription;
    cout << "Podaj projekt: " << endl;
    cout << "a) Nazwa: ";
    is >> projectName;
    cout << "b) Opis: ";
    is >> projectDescription;

    project = make_shared<Project>(projectName, 1, projectDescription);
    return is;
}