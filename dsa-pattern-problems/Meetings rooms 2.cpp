#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Problem: Meeting Rooms II
//
// Given an array of meeting time intervals where
// intervals[i] = [start, end], determine the minimum
// number of conference rooms required.
//
// Example:
// Input: [[0,30],[5,10],[15,20]]
// Output: 2
//
// Explanation:
// Meeting [0,30] overlaps with [5,10], so we need
// at least 2 rooms.
//
// Approach:
// - Separate start and end times.
// - Sort both arrays.
// - Use two pointers to track ongoing meetings.
// - If a meeting starts before the earliest meeting ends,
//   allocate a new room.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// ============================================================

int minMeetingRooms(vector<vector<int>>& intervals) {

    int n = intervals.size();

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms = 0;
    int endPtr = 0;

    for (int i = 0; i < n; i++) {

        if (start[i] < end[endPtr]) {
            rooms++;
        } 
        else {
            endPtr++;
        }
    }

    return rooms;
}

int main() {

    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};

    cout << "Minimum Meeting Rooms Needed: " << minMeetingRooms(intervals) << endl;

    return 0;
}
