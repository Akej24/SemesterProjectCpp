#include "employee.h"
#include <string>

using namespace std;

string capitalizeFirstLetter(const string &s) {
    if (s.empty())
        return "";

    string result = s;
    result[0] = toupper(result[0]);
    return result;
}
