/*. Given an array A[0…n-1] of n numbers containing repetition of some number. Give an algorithm for checking whether there are repeated element or not. Assume that we are not allowed to use additional space (i.e., we can use a few temporary variable, O(1) storage).*/
#include <iostream>
#include <cmath>

using namespace std;

bool hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        // Mark the element at the absolute value of arr[i] as visited
        int index = abs(arr[i]);

        if (arr[index] < 0) {
            // If the element is already marked as visited, it's a duplicate
            return true;
        } else {
            // Mark the element as visited by negating its value
            arr[index] = -arr[index];
        }
    }

    return false; // No duplicates found
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n)) {
        cout << "The array has duplicates." << endl;
    } else {
        cout << "The array does not have duplicates." << endl;
    }

    return 0;
}
