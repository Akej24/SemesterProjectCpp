#include "../header_files/Employee.hpp"

Employee::Employee(EmployeeInitializationDataWithProject data) {
    tie(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department, projects) = data;
}

Employee::Employee(EmployeeInitializationData data) {
    tie(id, name, age, firstName, lastName, workedHours, salaryPerHour, address, department) = data;
}

void Employee::deleteEmployee() {
    delete this;
}

void Employee::addProject(Project *project) {
    if (projects == nullptr) {
        projects = new Project *[2];
        projects[0] = project;
        projects[1] = nullptr;
    } else {
        int newSize = 0;
        while (projects[newSize] != nullptr)
            newSize++;
        newSize++;
        Project **newProjects = new Project *[newSize + 1];
        for (int i = 0; i < newSize - 1; ++i)
            newProjects[i] = projects[i];
        newProjects[newSize - 1] = project;
        newProjects[newSize] = nullptr;
        delete[] projects;
        projects = newProjects;
    }
}

void Employee::deleteProject(Project *project) {
    if (projects == nullptr)
        return;

    int foundProjectIndex = 0;
    while (projects[foundProjectIndex] != nullptr && projects[foundProjectIndex] != project)
        ++foundProjectIndex;

    if (projects[foundProjectIndex] == nullptr)
        return;

    delete projects[foundProjectIndex];
    for (int i = foundProjectIndex; projects[i] != nullptr; i++) {
        projects[i] = projects[i + 1];
    }

    if (projects[0] == nullptr) {
        delete[] projects;
        projects = nullptr;
    }
}

double Employee::calculateSalary() const {
    if (hasRaise)
        return workedHours * salaryPerHour + 1000;
    else
        return workedHours * salaryPerHour;
}

int Employee::countProjects() const {
    if (projects == nullptr)
        return 0;
    int projectCount = 0;
    while (projects[projectCount] != nullptr)
        projectCount++;
    return projectCount;
}

void Employee::presentEmployee() {
    cout << "Employee " << firstName << " " << Utils::capitalizeFirstLetter(lastName)
         << " has " << age << " years old and works in department " << department->getName() << endl;
}
