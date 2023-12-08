#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int profit;
    double ratio; // Profit-weight ratio
};

// Function to solve Fractional Knapsack problem using Largest-profit strategy
double knapsackLargestProfit(vector<Item>& items, int capacity) {
    for (int i = 0; i < items.size(); ++i) {
        for (int j = i + 1; j < items.size(); ++j) {
            if (items[i].profit < items[j].profit) {
                swap(items[i], items[j]);
            }
        }
    }

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (Item& item : items) {
        item.ratio = static_cast<double>(item.profit) / item.weight;
    }

    for (const Item& item : items) {
        int quantity = min(remainingCapacity, item.weight);
        totalProfit += quantity * item.ratio;
        remainingCapacity -= quantity;

        if (remainingCapacity == 0) {
            break;
        }
    }

    return totalProfit;
}

// Function to solve Fractional Knapsack problem using Smallest-weight strategy
double knapsackSmallestWeight(vector<Item>& items, int capacity) {
    for (int i = 0; i < items.size(); ++i) {
        for (int j = i + 1; j < items.size(); ++j) {
            if (items[i].weight > items[j].weight) {
                swap(items[i], items[j]);
            }
        }
    }

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (Item& item : items) {
        item.ratio = static_cast<double>(item.profit) / item.weight;
    }

    for (const Item& item : items) {
        int quantity = min(remainingCapacity, item.weight);
        totalProfit += quantity * item.ratio;
        remainingCapacity -= quantity;

        if (remainingCapacity == 0) {
            break;
        }
    }

    return totalProfit;
}

// Function to solve Fractional Knapsack problem using Largest profit-weight ratio strategy
double knapsackLargestRatio(vector<Item>& items, int capacity) {
    for (int i = 0; i < items.size(); ++i) {
        for (int j = i + 1; j < items.size(); ++j) {
            if (items[i].ratio < items[j].ratio) {
                swap(items[i], items[j]);
            }
        }
    }

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        int quantity = min(remainingCapacity, item.weight);
        totalProfit += quantity * item.ratio;
        remainingCapacity -= quantity;

        if (remainingCapacity == 0) {
            break;
        }
    }

    return totalProfit;
}

int main() {
    // Example items and capacity
    vector<Item> items = {
        {18, 25, 0.0},  // item 1
        {15, 24, 0.0},  // item 2
        {10, 15, 0.0}   // item 3
    };

    int capacity = 20;

    // Calculate total profit using different strategies
    double largestProfit = knapsackLargestProfit(items, capacity);
    double smallestWeight = knapsackSmallestWeight(items, capacity);
    double largestRatio = knapsackLargestRatio(items, capacity);

    // Display the results
    cout << "Total profit using Largest-profit strategy: " << largestProfit << endl;
    cout << "Total profit using Smallest-weight strategy: " << smallestWeight << endl;
    cout << "Total profit using Largest profit-weight ratio strategy: " << largestRatio << endl;

    return 0;
}
