#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Trapping Rain Water
//
// Given n non-negative integers representing elevation map
// where the width of each bar is 1, compute how much water
// it can trap after raining.
//
// Example:
// Input:  [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//
// Explanation:
// Water is trapped between taller bars.
//
// Approach (Optimal - Two Pointer):
// - Use two pointers: left and right.
// - Maintain leftMax and rightMax.
// - Move the pointer with smaller height.
// - If current height < max height seen so far,
//   water can be trapped.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

int trap(vector<int>& height) {

    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left < right) {

        // If left height is smaller
        if (height[left] < height[right]) {

            // Update leftMax
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                // Water trapped at this position
                totalWater += leftMax - height[left];
            }

            left++;
        }
        else {

            // Update rightMax
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                // Water trapped at this position
                totalWater += rightMax - height[right];
            }

            right--;
        }
    }

    return totalWater;
}

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = trap(height);

    cout << "Total Water Trapped: " << result;

    return 0;
}
