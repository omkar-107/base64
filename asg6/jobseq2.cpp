#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    char id;      // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
};

// Structure to represent a subset for Disjoint-Set
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a set using path compression
int find(vector<Subset> &subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Function to perform union of two sets using rank
void unionSets(vector<Subset> &subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the maximum profit job sequence using Disjoint-Set
void jobSequencingWithDeadlines(vector<Job> &jobs) {
    int n = jobs.size();
    vector<Subset> subsets(n);

    // Initialize subsets
    for (int i = 0; i < n; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort jobs based on their profit in non-decreasing order
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return (a.profit > b.profit);
    });

    // Initialize result sequence and time slots
    vector<char> result(n, '0');
    vector<bool> slot(n, false);

    // Fill the result sequence using Disjoint-Set
    for (int i = 0; i < n; ++i) {
        int availableSlot = find(subsets, min(n, jobs[i].deadline) - 1);

        // If the slot is available, add the job to the result sequence and union the sets
        if (availableSlot >= 0 && !slot[availableSlot]) {
            result[availableSlot] = jobs[i].id;
            slot[availableSlot] = true;
            unionSets(subsets, availableSlot, availableSlot - 1);
        }
    }

    // Display the result
    cout << "Job sequence with maximum profit: ";
    for (char jobId : result) {
        if (jobId != '0') {
            cout << jobId << " ";
        }
    }
    cout << endl;
}

int main() {
    // Example jobs with deadlines and profits
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    // Solve the Job Sequencing with Deadlines problem using Disjoint-Set
    jobSequencingWithDeadlines(jobs);

    return 0;
}
