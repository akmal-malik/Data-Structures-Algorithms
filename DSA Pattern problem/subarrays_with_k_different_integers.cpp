// Problem: Subarrays with k different integers
// ------------------------------------------------------------
// Problem Description:
// Given an array A[] of positive integers, find the number of 
// subarrays having exactly k distinct integers.
// ------------------------------------------------------------
// Approach: Sliding Window Technique
// Use two pointers (left and right) to maintain a sliding window 
// that contains exactly k distinct integers. Use an unordered_map 
// to keep track of the frequency of each integer in the current 
// window. Move the right pointer to expand the window and the 
// left pointer to shrink the window when it contains more than k 
// distinct integers. Count the number of valid subarrays.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(K), where K is the number of distinct integers.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0, result = 0;
        
        while (right < n) {
            freq[A[right]]++;
            while (freq.size() > K) {
                freq[A[left]]--;
                if (freq[A[left]] == 0) {
                    freq.erase(A[left]);
                }
                left++;
            }
            count = 0;
            while (left <= right && freq.size() == K) {
                count++;
                freq[A[left]]--;
                if (freq[A[left]] == 0) {
                    freq.erase(A[left]);
                }
                left++;
            }
            result += count;
            right++;
        }
        return result;
    }
};