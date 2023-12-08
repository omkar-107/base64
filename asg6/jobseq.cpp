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

// Function to compare jobs based on their profit (used for sorting)
bool compareJobs(const Job &a, const Job &b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void jobSequencingWithDeadlines(vector<Job> &jobs) {
    // Sort jobs based on their profit in non-decreasing order
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    vector<char> result(n, '0'); // To store the result sequence
    vector<bool> slot(n, false); // To keep track of time slots

    // Fill the result sequence and update time slots
    for (int i = 0; i < n; ++i) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
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

    // Solve the Job Sequencing with Deadlines problem
    jobSequencingWithDeadlines(jobs);

    return 0;
}
