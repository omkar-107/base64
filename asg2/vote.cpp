/*
Given an array A[0…n-1] , where each element of the array represents a vote in the election. Assume that each vote is given as an integer representing the ID of the chosen candidate. Given an algorithm for determining who wins the election*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findWinner(const vector<int>& votes) {
    unordered_map<int, int> voteCount;

    for (int vote : votes) {
        // Count the votes for each candidate
        voteCount[vote]++;
    }

    int maxVotes = 0;
    int winner = -1;

    // Find the candidate with the maximum votes
    for (const auto& entry : voteCount) {
        if (entry.second > maxVotes) {
            maxVotes = entry.second;
            winner = entry.first;
        }
    }

    return winner;
}

int main() {
    vector<int> votes = {1, 2, 3, 2, 1, 3, 1, 1, 2, 2, 3};

    int winner = findWinner(votes);

    if (winner != -1) {
        cout << "Candidate " << winner << " wins the election!" << endl;
    } else {
        cout << "No winner. It's a tie!" << endl;
    }

    return 0;
}
