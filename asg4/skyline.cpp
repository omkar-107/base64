#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Structure to represent a building
struct Building {
    int left;
    int height;
    int right;

    Building(int left, int height, int right) : left(left), height(height), right(right) {}
};

// Structure to represent a key point in the skyline
struct KeyPoint {
    int x;
    int height;

    KeyPoint(int x, int height) : x(x), height(height) {}
};

// Comparison function for the priority queue
struct CompareHeight {
    bool operator()(const KeyPoint& kp1, const KeyPoint& kp2) {
        return kp1.height < kp2.height;
    }
};

// Function to compute the skyline
std::vector<KeyPoint> getSkyline(const std::vector<Building>& buildings) {
    std::vector<KeyPoint> skyline;
    std::priority_queue<KeyPoint, std::vector<KeyPoint>, CompareHeight> maxHeap;

    // Combine left and right points of each building
    std::vector<KeyPoint> buildingPoints;
    for (const Building& building : buildings) {
        buildingPoints.emplace_back(building.left, building.height);
        buildingPoints.emplace_back(building.right, -building.height); // Use negative height for right points
    }

    // Sort building points based on x-coordinate
    std::sort(buildingPoints.begin(), buildingPoints.end(), [](const KeyPoint& kp1, const KeyPoint& kp2) {
        if (kp1.x != kp2.x) {
            return kp1.x < kp2.x;
        }
        return kp1.height < kp2.height;
    });

    int prevMaxHeight = 0;
    maxHeap.push({0, 0}); // Add a dummy point to simplify the algorithm

    for (const KeyPoint& point : buildingPoints) {
        if (point.height > 0) {
            maxHeap.push(point);
        } else {
            // Remove corresponding left point from the max heap
            while (!maxHeap.empty() && maxHeap.top().height < -point.height) {
                maxHeap.pop();
            }
        }

        // Get the current max height from the max heap
        int currentMaxHeight = maxHeap.top().height;

        // If the max height changes, add the key point to the skyline
        if (prevMaxHeight != currentMaxHeight) {
            skyline.emplace_back(point.x, currentMaxHeight);
            prevMaxHeight = currentMaxHeight;
        }
    }

    return skyline;
}

// Function to print the skyline
void printSkyline(const std::vector<KeyPoint>& skyline) {
    for (const KeyPoint& point : skyline) {
        std::cout << "(" << point.x << ", " << point.height << ") ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Building> buildings = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8}
    };

    std::vector<KeyPoint> skyline = getSkyline(buildings);

    std::cout << "Skyline points:\n";
    printSkyline(skyline);

    return 0;
}
