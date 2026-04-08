// Problem: Capacity to ship packages
// ------------------------------------------------------------
// Problem Description:
// Given an array of positive integers representing the weights of packages, and a positive integer days, 
// determine the minimum capacity of the ship required so that all packages can be shipped within days days.
// Each day, the ship can only ship one package. The capacity must be at least the maximum weight of a single package.
// ------------------------------------------------------------
// Approach: Binary Search
// Perform binary search on the possible ship capacities. The lower bound is the maximum weight of a single package,
// and the upper bound is the sum of all package weights. For each capacity, check if it's possible to ship all packages
// within the given days using the greedy approach.
// ------------------------------------------------------------
// Time Complexity: O(n log(sum(weights)))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currentCapacity = mid;
            int daysNeeded = 1;
            int i = 0;
            
            while (i < weights.size()) {
                if (currentCapacity >= weights[i]) {
                    currentCapacity -= weights[i];
                    i++;
                } else {
                    daysNeeded++;
                    currentCapacity = mid;
                }
            }
            
            if (daysNeeded <= days) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};