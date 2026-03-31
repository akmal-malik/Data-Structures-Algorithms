// Problem: Minimum cost to hire k workers
// ------------------------------------------------------------
// Problem Description:
// Given a list of workers and their individual quality, we need to hire exactly k workers 
// such that the total quality of hired workers is maximized. The cost of hiring a worker 
// is calculated as the product of his/her quality and the sum of qualities of all currently hired workers.
// ------------------------------------------------------------
// Approach: Priority Queue (Max Heap)
// We use a max heap to keep track of the k workers with the highest quality. The cost 
// of hiring a new worker is calculated by multiplying their quality with the current total 
// quality of all hired workers.
// ------------------------------------------------------------
// Time Complexity: O(n log n) due to sorting and heap operations
// Space Complexity: O(n) for storing the priority queue
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> unitWage(n);
        
        // Calculate unit wage for each worker
        for (int i = 0; i < n; ++i)
            unitWage[i] = {static_cast<double>(wage[i]) / quality[i], quality[i]};
        
        // Sort workers by their unit wage in descending order
        sort(unitWage.begin(), unitWage.end(), greater<pair<double, int>>());
        
        double totalQuality = 0, minCost = DBL_MAX;
        priority_queue<int> pq;
        
        for (auto& [wagePerUnit, q] : unitWage) {
            totalQuality += q;
            pq.push(q);
            
            if (pq.size() > k)
                totalQuality -= pq.top(), pq.pop();
            
            if (pq.size() == k)
                minCost = min(minCost, wagePerUnit * totalQuality);
        }
        
        return minCost;
    }
};