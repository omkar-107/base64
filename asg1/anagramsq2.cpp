#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isAnagram(const string& str1, const string& str2) {
    // Sort both strings and check if they are equal
    string sortedStr1 = str1;
    string sortedStr2 = str2;
    sort(sortedStr1.begin(), sortedStr1.end());
    sort(sortedStr2.begin(), sortedStr2.end());
    return sortedStr1 == sortedStr2;
}

void groupAnagrams(vector<string>& arr) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& word : arr) {
        bool addedToGroup = false;

        // Check if the word can be added to an existing group
        for (auto& group : anagramGroups) {
            if (isAnagram(group.first, word)) {
                group.second.push_back(word);
                addedToGroup = true;
                break;
            }
        }

        // If the word doesn't fit into any existing group, create a new group
        if (!addedToGroup) {
            anagramGroups[word].push_back(word);
        }
    }

    // Reconstruct the array with grouped anagrams
    arr.clear();
    for (const auto& group : anagramGroups) {
        arr.insert(arr.end(), group.second.begin(), group.second.end());
    }
}

int main() {
    vector<string> arr = {"tap", "pat", "apt", "rat", "act", "tan", "art"};

    cout << "Before sorting:" << endl;
    for (const string& word : arr) {
        cout << word << " ";
    }
    cout << "\n" << endl;

    groupAnagrams(arr);

    cout << "After sorting:" << endl;
    for (const string& word : arr) {
        cout << word << " ";
    }
    cout << "\n" << endl;

    return 0;
}
