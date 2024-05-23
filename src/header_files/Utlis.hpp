#ifndef UTILS
#define UTILS

#include <string>

using namespace std;

string capitalizeFirstLetter(const string &s);

class Utils final {
private:
    Utils();

public:
    static string capitalizeFirstLetter(const string &s);
};

#endif