//Given an M*N matrix in which each row and each column is sorted in ascending order, write a method to find an element.
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchMatrix(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
        return {-1, -1}; // Matrix is empty
    }

    int n = matrix[0].size();
    if (n == 0) {
        return {-1, -1}; // Matrix is empty
    }

    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return {row, col}; // Element found
        } else if (matrix[row][col] < target) {
            row++; // Move to the next row
        } else {
            col--; // Move to the previous column
        }
    }

    return {-1, -1}; // Element not found
}

int main() {
    vector<vector<int>> matrix = {
        { 10, 20, 30, 40 }, 
        { 15, 25, 35, 45 }, 
        { 27, 29, 37, 48 }, 
        { 32, 33, 39, 50 } 
    };

    int target = 29;

    pair<int, int> result = searchMatrix(matrix, target);

    if (result.first != -1 && result.second != -1) {
        cout << "Element " << target << " found at position (" << result.first << ", " << result.second << ")\n";
    } else {
        cout << "Element " << target << " not found in the matrix\n";
    }

    return 0;
}

