// Problem: Next greater element
// ------------------------------------------------------------
// Problem Description:
// Given an array, find the next greater element for every element in the array. 
// The next greater element for an element in the array is the first greater element 
// to its right side. If there is no greater element to the right side, return -1.
// ------------------------------------------------------------
// Approach: Stack
// Traverse the array from right to left. Use a stack to keep track of the next greater elements.
// For each element, pop elements from the stack that are smaller than the current element.
// The next greater element for the current element is the top of the stack after the pop operations.
// If the stack is empty, it means there is no greater element to the right, so push -1.
// Push the current element onto the stack.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
        
        return result;
    }
};