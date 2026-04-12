// Problem: First bad version
// ------------------------------------------------------------
// Problem Description:
// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product has some issues, and you are tasked with finding the first bad version. Given a list of versions [1, 2, ..., n] and you know that one of these versions is bad, determine the first bad version. You should minimize the number of calls to the API `isBadVersion(version)`, which returns true if the version is bad and false if it is good.
// ------------------------------------------------------------
// Approach: Binary Search
// Use binary search to minimize the number of calls to `isBadVersion`. Compare the middle element with the version that returns true, and adjust the search range accordingly.
// ------------------------------------------------------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};