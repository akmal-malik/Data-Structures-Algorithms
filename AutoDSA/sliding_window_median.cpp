// Problem: Sliding window median
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and a sliding window of size k, return the median of all subarrays of size k.
// The median is the middle value when a data set is ordered from least to greatest. If there is an even number 
// of observations, the median is the average of the two middle numbers.
// ------------------------------------------------------------
// Approach: Multiset
// Use a multiset to store the elements in the current window, allowing for efficient insertion and deletion of elements,
// as well as quick access to the median value.
// ------------------------------------------------------------
// Time Complexity: O(n log k)
// Space Complexity: O(k)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> medians;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Add the new element to the window
            window.insert(nums[i]);
            
            // Remove the element that is no longer in the window
            if (i >= k) {
                auto it = window.find(nums[i - k]);
                if (it != window.end()) {
                    window.erase(it);
                }
            }
            
            // Calculate the median of the current window
            int size = window.size();
            if (size % 2 == 0) {
                double median1 = *next(window.begin(), size / 2 - 1);
                double median2 = *next(window.begin(), size / 2);
                medians.push_back((median1 + median2) / 2.0);
            } else {
                medians.push_back(*next(window.begin(), size / 2));
            }
        }
        
        return medians;
    }
};