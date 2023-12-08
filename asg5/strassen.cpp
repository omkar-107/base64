#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to perform Strassen's matrix multiplication
vector<vector<int>> strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrix size is 1x1, perform a simple multiplication
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Divide the matrices into four submatrices
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid, 0));
    vector<vector<int>> A12(mid, vector<int>(mid, 0));
    vector<vector<int>> A21(mid, vector<int>(mid, 0));
    vector<vector<int>> A22(mid, vector<int>(mid, 0));

    vector<vector<int>> B11(mid, vector<int>(mid, 0));
    vector<vector<int>> B12(mid, vector<int>(mid, 0));
    vector<vector<int>> B21(mid, vector<int>(mid, 0));
    vector<vector<int>> B22(mid, vector<int>(mid, 0));

    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Recursive steps
    vector<vector<int>> P1 = strassenMultiplication(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P2 = strassenMultiplication(matrixAddition(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiplication(matrixAddition(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiplication(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5 = strassenMultiplication(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> P6 = strassenMultiplication(matrixSubtraction(A12, A22), matrixAddition(B21, B22));
    vector<vector<int>> P7 = strassenMultiplication(matrixSubtraction(A11, A21), matrixAddition(B11, B12));

    // Combine the results to get the final matrix
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            result[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            result[i][j + mid] = P1[i][j] + P2[i][j];
            result[i + mid][j] = P3[i][j] + P4[i][j];
            result[i + mid][j + mid] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices A and B
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    // Multiply matrices A and B using Strassen's algorithm
    vector<vector<int>> result = strassenMultiplication(A, B);

    // Print the result matrix
    cout << "Result matrix:" << endl;
    printMatrix(result);

    return 0;
}
