#ifndef UTILS
#define UTILS

#include <string>

using namespace std;

class Utils final {
private:
    Utils() = delete;

public:
    static string capitalizeFirstLetter(const string &word);
};

#endif
