#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Find a Peak Element
//
// A peak element is an element that is greater than its neighbors.
// Return the index of any peak element.
//
// Example:
// Input:  [1, 2, 3, 1]
// Output: 2  (because nums[2] = 3 is a peak)
//
// Approach:
// - Use Binary Search.
// - Compare middle element with the next element.
// - If nums[mid] < nums[mid+1], peak is on the right side.
// - Otherwise peak is on the left side.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ============================================================

int findPeakElement(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {

    vector<int> nums = {1, 2, 3, 1};

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak value: " << nums[peakIndex] << endl;

    return 0;
}
