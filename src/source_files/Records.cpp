#include "../header_files/Records.hpp"

string extractFirstName(const string &sentence) {
    size_t start = sentence.find("Employee ") + 9;
    size_t end = sentence.find(" ", start);
    return sentence.substr(start, end - start);
}

string extractLastName(const string &sentence) {
    size_t start = sentence.find(" ") + 1;
    size_t end = sentence.find(" has ", start);
    return sentence.substr(start, end - start);
}

int extractProjectsAmount(const string &sentence) {
    size_t start = sentence.find(" has ") + 5;
    size_t end = sentence.find(" projects", start);
    return stoi(sentence.substr(start, end - start));
}

void extractAttributesFromRecords(const string *records, int size) {
    for (int i = 0; i < size; ++i) {
        if (!records[i].empty()) {
            string firstName = extractFirstName(records[i]);
            string lastName = extractLastName(records[i]);
            int projectsAmount = extractProjectsAmount(records[i]);
            cout << "Wyodrebnione dane: " << endl;
            cout << "- firstName: " << firstName << endl;
            cout << "- lastName: " << lastName << endl;
            cout << "- projectsAmount: " << projectsAmount << endl;
        }
    }
}