#include "../header_files/Utlis.hpp"

string Utils::capitalizeFirstLetter(const string &word) {
    if (word.empty())
        return "";
    string result = word;
    result[0] = toupper(result[0]);
    return result;
}