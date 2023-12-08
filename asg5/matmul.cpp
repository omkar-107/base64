#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();    // Number of rows in A
    int n = A[0].size(); // Number of columns in A
    int p = B[0].size(); // Number of columns in B

    // Initialize the result matrix with zeros
    vector<vector<int>> result(m, vector<int>(p, 0));

    // Naive matrix multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices A and B
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Multiply matrices A and B
    vector<vector<int>> result = multiplyMatrices(A, B);

    // Print the result matrix
    cout << "Result matrix:" << endl;
    printMatrix(result);

    return 0;
}
