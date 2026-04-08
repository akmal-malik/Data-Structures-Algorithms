// Problem: Sliding window maximum
// ------------------------------------------------------------
// Problem Description:
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves one position to the right, return the max number in the sliding window.
// ------------------------------------------------------------
// Approach: Deque
// Use a deque to store the indices of elements in the current window. The deque will maintain elements in decreasing order. This way, the front of the deque will always contain the maximum element in the current window.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(k)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements not within the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // Add the current element's index to the back
            dq.push_back(i);
            // The front of the deque is the maximum element for the current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};