#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Move all zeros to the end of the array
// while maintaining the relative order of non-zero elements.
//
// Example:
// Input:  [0, 1, 0, 3, 12]
// Output: [1, 3, 12, 0, 0]
//
// Approach:
// - Use a pointer 'j' to track the position where the
//   next non-zero element should be placed.
// - Traverse the array using index 'i'.
// - Whenever nums[i] != 0, swap nums[i] with nums[j]
//   and increment j.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

void moveZeros(vector<int>& nums) {
    int j = 0;  // Position to place next non-zero element

    for (int i = 0; i < nums.size(); i++) {

        // If current element is non-zero
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;  // Move j forward
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeros(nums);

    // Print modified array
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
