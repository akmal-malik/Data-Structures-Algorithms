// Problem: Split array largest sum
// ------------------------------------------------------------
// Problem Description:
// Given an array which consists of non-negative integers and an integer m, 
// you can split the array into m non-empty continuous subarrays. 
// Write an algorithm to minimize the largest sum among these m subarrays.
// ------------------------------------------------------------
// Approach: Binary Search
// The problem can be solved using binary search on the possible range of the largest sum. 
// We initialize the search range between the maximum element and the sum of all elements.
// ------------------------------------------------------------
// Time Complexity: O(n log(sum - max)), where n is the number of elements in the array.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, m, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
private:
    bool canSplit(vector<int>& nums, int m, int maxSum) {
        int count = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (num > maxSum) return false;
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        
        return count <= m;
    }
};