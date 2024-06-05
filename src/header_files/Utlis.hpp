#ifndef UTILS
#define UTILS

#include <string>

using namespace std;

class Utils final {
private:
    Utils();

public:
    static string capitalizeFirstLetter(const string &s);
};

#endif