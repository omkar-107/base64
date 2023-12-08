// Implement algorithm to Find the maximum element in an array which is first increasing and then decreasing, with Time Complexity O(Logn).
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            // The peak element is to the left
            right = mid;
        } else {
            // The peak element is to the right
            left = mid + 1;
        }
    }

    // At the end of the loop, left and right point to the peak element
    return arr[left];
}

int main() {
    vector<int> arr = {1, 3, 8, 4, 2};

    cout << "Maximum element: " << findPeakElement(arr) << endl;

    return 0;
}
/*
#include <iostream>
#include <vector>

using namespace std;

int searchInArray(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target element found
        }

        // Check which half is sorted and contains the target
        if (arr[left] <= arr[mid]) {
            // Left half is sorted

            if (arr[left] <= target && target < arr[mid]) {
                // Target is in the left half
                right = mid - 1;
            } else {
                // Target is in the right half
                left = mid + 1;
            }
        } else {
            // Right half is sorted

            if (arr[mid] < target && target <= arr[right]) {
                // Target is in the right half
                left = mid + 1;
            } else {
                // Target is in the left half
                right = mid - 1;
            }
        }
    }

    return -1;  // Target element not found
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};
    int target = 4;

    int result = searchInArray(arr, target);

    if (result != -1) {
        cout << "Target element " << target << " found at index " << result << endl;
    } else {
        cout << "Target element " << target << " not found in the array" << endl;
    }

    return 0;
}
*/