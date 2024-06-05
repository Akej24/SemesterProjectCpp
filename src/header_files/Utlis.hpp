#ifndef UTILS
#define UTILS

#include <string>

using namespace std;

class Utils final {
private:
    Utils();

public:
    static string capitalizeFirstLetter(const string &word) {
        if (word.empty())
            return "";
        string result = word;
        result[0] = toupper(result[0]);
        return result;
    }
};

#endif