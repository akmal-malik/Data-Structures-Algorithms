// Problem: Minimize max distance to gas station
// ------------------------------------------------------------
// Problem Description:
// Given n gas stations along a road, represented by a list of their positions (sorted in non-decreasing order),
// and a car with an infinite gas tank and a fixed fuel capacity, determine the minimum possible maximum distance between any two stops of gas.
// The car must start at the first gas station and end at the last gas station without refueling more than once.
// ------------------------------------------------------------
// Approach: Binary Search
// Perform a binary search on the possible maximum distances to find the minimum value that satisfies the condition.
// ------------------------------------------------------------
// Time Complexity: O(n log d), where n is the number of gas stations and d is the maximum possible distance.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double lo = 0, hi = 1e8, mi;
        while (hi - lo > 1e-6) {
            mi = (lo + hi) / 2;
            int cnt = 0;
            for (int i = 1; i < stations.size(); i++) {
                cnt += ceil((stations[i] - stations[i - 1]) / mi) - 1;
            }
            if (cnt > K) lo = mi;
            else hi = mi;
        }
        return lo;
    }
};