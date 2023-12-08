/*
A circus is designing a tower routine consisting of people standing atop one another’s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weight of each circus, write a method to compute the largest possible number of people in such tower.
EXAMPLE:
Input(ht,wt): (65, 100) (70, 150) (56, 90) (75,190) (60, 95) (68, 110).
Output: The longest tower is length 6 and includes from top to bottom:
(56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int height;
    int weight;
};

bool comparePeople(const Person& p1, const Person& p2) {
    if (p1.height == p2.height) {
        return p1.weight < p2.weight;
    }
    return p1.height < p2.height;
}

int longestTower(vector<Person>& people) {
    sort(people.begin(), people.end(), comparePeople);

    vector<int> dp(people.size(), 1);

    for (int i = 1; i < people.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (people[i].weight > people[j].weight) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Person> people = {
        {65, 100},
        {70, 150},
        {56, 90},
        {75, 190},
        {60, 95},
        {68, 110}
    };

    int result = longestTower(people);

    cout << "The longest tower is length " << result << " and includes from top to bottom:" << endl;
    for (const Person& p : people) {
        cout << "(" << p.height << ", " << p.weight << ") ";
    }
    cout << endl;

    return 0;
}
