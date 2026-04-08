/*
🔥 Problem: Gas Station

🧠 Approach:
We use a greedy strategy based on key observations.

Key Idea:
1. If total gas < total cost → impossible to complete circuit
2. If tank becomes negative at any point:
   - Current starting point is invalid
   - Move start to next station
   - Reset tank

Why it works:
- If we fail between A → B, then any station between A and B
  also cannot be a valid start.

⏱ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;   // Total gas available
        int totalCost = 0;  // Total cost required
        int tank = 0;       // Current tank
        int start = 0;      // Starting index

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            tank += gas[i] - cost[i];

            // If tank becomes negative, reset start
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // Check if overall journey is possible
        if (totalGas < totalCost) return -1;

        return start;
    }
};
