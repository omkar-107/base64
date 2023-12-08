/*
Q) Given a sorted array of string which is interspersed with empty string, write a method to find the location of a given string.
EXAMPLE
Input: find “ball” in {“at”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”,””}
Output: 4
*/


#include <iostream>
#include <vector>

using namespace std;

int findStringLocation(const vector<string>& arr, const string& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // Skip any empty strings at the beginning
        while (left <= right && arr[left].empty()) {
            left++;
        }

        // Skip any empty strings at the end
        while (left <= right && arr[right].empty()) {
            right--;
        }

        int mid = left + (right - left) / 2;

        // Skip any empty strings at mid
        while (arr[mid].empty() && mid < right) {
            mid++;
        }

        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    vector<string> array = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

    string target = "ball";

    int result = findStringLocation(array, target);

    if (result != -1) {
        cout << "String " << target << " found at index " << result << endl;
    } else {
        cout << "String " << target << " not found in the array" << endl;
    }

    return 0;
}
