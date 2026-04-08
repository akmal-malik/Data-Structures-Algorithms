// Problem: K closest points
// ------------------------------------------------------------
// Problem Description:
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance: sqrt((x1 - x2)^2 + (y1 - y2)^2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it's in).
// Example 1:
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between origin and [1,3] is sqrt(10), and the distance between origin and [-2,2] is sqrt(8).
// Since sqrt(8) < sqrt(10), [-2,2] is closer to the origin.
// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation:
// The answer has been sorted according to the distance to the origin.
// It is not unique that the answer returned contains both [3,3] and [-2,4].
// It is also accepted that the answer contains only one of them.
// Note:
// 1 <= k <= points.length
// -10^4 < xi, yi < 10^4
// sqrt(x^2 + y^2) is smaller than sqrt(x^2 + y^2 + epsilon)
// ------------------------------------------------------------
// Approach: Min-Heap
// Use a min-heap to keep track of the k closest points. For each point, calculate its Euclidean distance from the origin and push it into the heap.
// If the heap size exceeds k, remove the farthest point (the root of the heap).
// After processing all points, the heap will contain the k closest points.
// ------------------------------------------------------------
// Time Complexity: O(n log k), where n is the number of points. We process each point once and perform heap operations which take logarithmic time.
// Space Complexity: O(k) for storing the min-heap.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        
        for (const auto& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            pq.push({distance, point});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};