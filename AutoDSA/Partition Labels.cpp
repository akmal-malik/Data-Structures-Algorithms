/*
🔥 Problem: Partition Labels

🧠 Approach:
We use a greedy strategy with last occurrence tracking.

Steps:
1. Store last occurrence index of each character
2. Traverse the string
3. Keep updating the current partition's end using max(last occurrence)
4. When current index == end → partition complete

Why it works:
- Ensures all occurrences of characters in current partition are included
- Greedily makes the smallest valid partitions → maximum count

⏱ Time Complexity: O(n)
📦 Space Complexity: O(1) (fixed 26 characters)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);

        // Step 1: Record last occurrence
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> partitions;
        int start = 0;
        int end = 0;

        // Step 2: Traverse and create partitions
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);

            // Partition boundary found
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};
