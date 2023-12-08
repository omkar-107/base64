//) Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.

#include <iostream>
#include <vector>

using namespace std;

int searchRotatedArray(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Element found
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // Check if the target is in the left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Adjust the search range to the left half
            } else {
                left = mid + 1; // Adjust the search range to the right half
            }
        } else {
            // Check if the target is in the right half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Adjust the search range to the right half
            } else {
                right = mid - 1; // Adjust the search range to the left half
            }
        }
    }

    return -1; // Element not found
}

int main() {
    vector<int> rotatedArray = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 5;

    int result = searchRotatedArray(rotatedArray, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
