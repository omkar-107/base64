//Given an array A of n elements, each of which is an integer in the range [1, n2]. How do we sort the array in O(n) time?
#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr, int n) {
    // Create a count array to store the frequency of each element
    vector<int> count(n + 1, 0);

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the cumulative count
    for (int i = 2; i <= n; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted result
    vector<int> output(n);
    
    // Build the sorted array using the count array
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {6, 3, 1, 2, 9, 4, 5, 8, 7, 10};
    int n = arr.size();

    cout << "Original array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr, n);

    cout << "Sorted array using Counting Sort:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
