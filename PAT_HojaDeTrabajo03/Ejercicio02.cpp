#include "Ejercicio02.h"
#include <string>
#include <vector>
#include <algorithm>

vector<vector<string>>* Ejercicio02::groupAnagrams(vector<string>& strings)
{
    vector<string> sortedStrings;
    vector<vector<string>> anagramGroups;

    for (const string& s : strings) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());

        auto it = find(sortedStrings.begin(), sortedStrings.end(), sortedStr);

        if (it != sortedStrings.end()) {
            size_t index = distance(sortedStrings.begin(), it);
            anagramGroups[index].push_back(s);
        }
        else {
            sortedStrings.push_back(sortedStr);
            anagramGroups.push_back({ s });
        }
    }

    auto result = new vector<vector<string>>(anagramGroups);

    return result;
}
