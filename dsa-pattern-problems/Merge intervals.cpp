#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Problem: Merge Intervals
//
// Given an array of intervals where intervals[i] = [start, end],
// merge all overlapping intervals and return the resulting
// non-overlapping intervals.
//
// Example:
// Input:  [[1,3], [2,6], [8,10], [15,18]]
// Output: [[1,6], [8,10], [15,18]]
//
// Explanation:
// Intervals [1,3] and [2,6] overlap, so they are merged into [1,6].
//
// Approach:
// - Sort intervals based on start time.
// - Iterate through intervals.
// - If the current interval overlaps with the last merged interval,
//   update the end time.
// - Otherwise, add it to the result.
//
// Time Complexity: O(n log n)  (due to sorting)
// Space Complexity: O(n)
// ============================================================

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (auto interval : intervals) {

        if (result.empty() || result.back()[1] < interval[0]) {
            result.push_back(interval);
        } 
        else {
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }

    return result;
}

int main() {

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals: ";
    for (auto i : result) {
        cout << "[" << i[0] << "," << i[1] << "] ";
    }

    return 0;
}
