#ifndef RECORDS
#define RECORDS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Records final {
private:
    Records();

public:
    static string extractFirstName(const string &sentence);
    static string extractLastName(const string &sentence);
    static string extractTitle(const string &sentence);
    static int extractProjectsAmount(const string &sentence);
    static void extractAttributesFromRecords(const string *records, int size);
};

#endif