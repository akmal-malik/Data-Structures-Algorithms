// Problem: Kth largest element
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// You must solve it in O(n) time complexity.
// ------------------------------------------------------------
// Approach: Quickselect Algorithm
// The quickselect algorithm is a selection algorithm to find the k-th smallest (or largest) element in an unordered list. It is related to the quicksort sorting algorithm.
// ------------------------------------------------------------ 
// Time Complexity: Average case - O(n), Worst case - O(n^2)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k - 1)
                return nums[pivotIndex];
            else if (pivotIndex < k - 1)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivotValue = nums[right];
        int storeIndex = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivotValue) {
                swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};