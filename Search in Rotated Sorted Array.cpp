#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Search in Rotated Sorted Array
//
// Given a rotated sorted array, search for a target value.
// Return its index, or -1 if not found.
//
// Example:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Approach:
// - Use Binary Search.
// - One half of the array is always sorted.
// - Check which half is sorted and decide where to search.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ============================================================

int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {

            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Right half is sorted
        else {

            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int index = search(nums, target);

    cout << "Target index: " << index << endl;

    return 0;
}
