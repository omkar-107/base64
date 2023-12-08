#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low + 1; // Index of the smaller element

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }

    swap(arr[low], arr[i - 1]);
    return i - 1; // Return the index of the pivot
}

// Function to perform the quicksort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {6, 3, 1, 8, 4, 9, 5, 2, 7};

    cout << "Original array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Quicksort
    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array using Quicksort:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
