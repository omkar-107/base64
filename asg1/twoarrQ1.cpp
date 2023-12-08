#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // sorted array 1
    int arr1[] = { 12, 23, 44, 51, -1, -1, -1, -1 };
    int arr2[] = { 11, 56, 90, 45 };

    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    cout << "arr1: ";
    for (int i = 0; i < arr1Size; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i = 0; i < arr2Size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int pos = 0;
    for (int i = 0; i < arr1Size; i++) {
        if (arr1[i] == -1) {
            pos = i;
            break;
        }
    }
    cout << "pos: " << pos << endl;

    for (int j : arr2) {
        int k = pos - 1;
        while (k >= 0 && j < arr1[k]) {
            arr1[k + 1] = arr1[k];
            k--;
        }
        arr1[k + 1] = j;
        pos++;
    }

    cout << "Merged array: ";
    for (int i = 0; i < arr1Size; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i = 0; i < arr2Size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
