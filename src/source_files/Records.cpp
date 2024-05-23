#include "../header_files/Records.hpp"

string Records::extractFirstName(const string &sentence) {
    size_t start = sentence.find("Employee ") + 9;
    size_t end = sentence.find(" ", start);
    return sentence.substr(start, end - start);
}

string Records::extractLastName(const string &sentence) {
    size_t start = sentence.find(" ") + 1;
    size_t end = sentence.find(" has ", start);
    return sentence.substr(start, end - start);
}

int Records::extractProjectsAmount(const string &sentence) {
    size_t start = sentence.find(" has ") + 5;
    size_t end = sentence.find(" projects", start);
    return stoi(sentence.substr(start, end - start));
}

string Records::extractTitle(const string &sentence) {
    size_t start = sentence.find(" has title ") + 11;
    return sentence.substr(start, sentence.length());
}

void Records::extractAttributesFromRecords(const string *records, int size) {
    for (int i = 0; i < size; ++i) {
        if (!records[i].empty()) {

            cout << "Wyodrebnione dane: " << endl;
            cout << "- firstName: " << extractFirstName(records[i]) << endl;
            cout << "- lastName: " << extractLastName(records[i]) << endl;

            if (records[i].find("Employee") != string::npos)
                cout << "- projectsAmount: " << extractProjectsAmount(records[i]) << endl;
            else
                cout << "- title: " << extractTitle(records[i]) << endl;
        }
    }
}