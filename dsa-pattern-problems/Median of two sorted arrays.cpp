#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ============================================================
// Problem: Median of Two Sorted Arrays
//
// Given two sorted arrays, find the median of both arrays.
//
// Example:
// nums1 = [1,3]
// nums2 = [2]
//
// Output: 2
//
// Approach:
// - Use Binary Search on the smaller array.
// - Partition both arrays so that left half and right half
//   satisfy the median condition.
//
// Time Complexity: O(log(min(n,m)))
// Space Complexity: O(1)
// ============================================================

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size())
        swap(nums1, nums2);

    int x = nums1.size();
    int y = nums2.size();

    int low = 0, high = x;

    while (low <= high) {

        int partX = (low + high) / 2;
        int partY = (x + y + 1) / 2 - partX;

        int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
        int minRightX = (partX == x) ? INT_MAX : nums1[partX];

        int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
        int minRightY = (partY == y) ? INT_MAX : nums2[partY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {

            if ((x + y) % 2 == 0)
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            else
                return max(maxLeftX, maxLeftY);
        }

        else if (maxLeftX > minRightY)
            high = partX - 1;
        else
            low = partX + 1;
    }

    return 0.0;
}

int main() {

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median: " << median << endl;

    return 0;
}
