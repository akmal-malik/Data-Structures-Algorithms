// Problem: Median of two sorted arrays
// ------------------------------------------------------------
// Problem Description:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).
// ------------------------------------------------------------
// Approach: Binary Search
// By using binary search, we can find the partition point in both arrays such that the left part contains the smaller numbers and the right part contains the larger numbers. The partition should also satisfy the condition that the number of elements on the left side is equal to the number of elements on the right side (or one more on the left side if the total number of elements is odd).
// ------------------------------------------------------------
// Time Complexity: O(log(min(m,n)))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        throw invalid_argument("Input arrays are not sorted");
    }
};