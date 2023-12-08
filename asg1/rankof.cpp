/*
Imagine you are reading in stream of integers. Periodically, you wish to be able to look up the rank of number x (the number of values less than or equal to x). Implement the data structures and algorithms to support these operations. That is, Implement the method track (int x), which is called when each number is generated, and the method getRankOfNumber (int x), which return the number of values less than or equal to x (not including x itself).
EXAMPLE
Stream (in order of appearance) : 5, 1, 4, 4, 5, 9, 7, 13, 3
 getRankOfNumber(1) = 0
getRankOfNumber(3) = 1
getRankOfNumber(4) =3
*/

#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    int leftCount;  // Number of elements in the left subtree
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), leftCount(0), left(nullptr), right(nullptr) {}
};

class RankTracker {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int x) {
        if (!node) {
            node = new TreeNode(x);
        } else if (x <= node->data) {
            node->leftCount++;
            insert(node->left, x);
        } else {
            insert(node->right, x);
        }
    }

    int getRank(TreeNode* node, int x) {
        if (!node) {
            return 0;
        }

        if (x == node->data) {
            return node->leftCount;
        } else if (x < node->data) {
            return getRank(node->left, x);
        } else {
            return 1 + node->leftCount + getRank(node->right, x);
        }
    }

public:
    RankTracker() : root(nullptr) {}

    void track(int x) {
        insert(root, x);
    }

    int getRankOfNumber(int x) {
        return getRank(root, x);
    }
};

int main() {
    RankTracker rankTracker;

    // Stream of integers
    int stream[] = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    int streamSize = sizeof(stream) / sizeof(stream[0]);

    // Track each number in the stream
    for (int i = 0; i < streamSize; ++i) {
        rankTracker.track(stream[i]);
    }

    // Example queries
    cout << "getRankOfNumber(1): " << rankTracker.getRankOfNumber(1) << endl; // Output: 0
    cout << "getRankOfNumber(3): " << rankTracker.getRankOfNumber(3) << endl; // Output: 1
    cout << "getRankOfNumber(4): " << rankTracker.getRankOfNumber(4) << endl; // Output: 3

    return 0;
}
