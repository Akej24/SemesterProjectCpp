#ifndef RECORDS
#define RECORDS

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string extractFirstName(const string &sentence);
string extractLastName(const string &sentence);
int extractProjectsAmount(const string &sentence);
void extractAttributesFromRecords(const string *records, int size);

#endif