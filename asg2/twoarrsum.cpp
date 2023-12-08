#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool hasSumPair(const vector<int>& A, const vector<int>& B, int K) {
    int n = A.size();
    int m = B.size();

    // Sort array B
    sort(B.begin(), B.end());

    // Check for pairs (a, b) such that a + b = K
    for (int i = 0; i < n; ++i) {
        int requiredValue = K - A[i];
        auto it = lower_bound(B.begin(), B.end(), requiredValue);

        if (it != B.end() && *it == requiredValue) {
            return true; // Found a pair (A[i], B[j]) such that A[i] + B[j] = K
        }
    }

    return false; // No such pair found
}

int main() {
    vector<int> A = {1, 4, 6, 8};
    vector<int> B = {2, 3, 5, 7};
    int K = 10;

    if (hasSumPair(A, B, K)) {
        cout << "There exists a pair (a, b) such that a + b = " << K << endl;
    } else {
        cout << "No such pair exists." << endl;
    }

    return 0;
}
