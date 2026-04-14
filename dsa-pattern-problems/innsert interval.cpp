#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Insert Interval
//
// You are given a list of non-overlapping intervals sorted
// by start time. Insert a new interval into the list and merge
// if necessary.
//
// Example:
// Input:
// intervals = [[1,3],[6,9]]
// newInterval = [2,5]
//
// Output:
// [[1,5],[6,9]]
//
// Approach:
// - Add intervals that end before the new interval starts.
// - Merge overlapping intervals.
// - Add remaining intervals.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// ============================================================

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    result.push_back(newInterval);

    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main() {

    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    cout << "Intervals after insertion: ";
    for (auto i : result) {
        cout << "[" << i[0] << "," << i[1] << "] ";
    }

    return 0;
}
