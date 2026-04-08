// Problem: Reorganize String
// ------------------------------------------------------------
// Problem Description:
// Given a string s, rearrange the characters of s so that no two adjacent characters are the same.
// Return any possible rearrangement of s. If no such arrangement exists, return an empty string.
// ------------------------------------------------------------
// Approach: Priority Queue (Max Heap)
// Use a priority queue to always pick the most frequent character that is different from the last placed one.
// ------------------------------------------------------------
// Time Complexity: O(N log N), where N is the length of the string
// Space Complexity: O(1) since the size of the heap is bounded by the number of unique characters (at most 26 for English alphabet)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                maxHeap.push({count[i], 'a' + i});
            }
        }
        
        string result = "";
        while (maxHeap.size() >= 2) {
            auto top1 = maxHeap.top(); maxHeap.pop();
            auto top2 = maxHeap.top(); maxHeap.pop();
            
            result += top1.second;
            result += top2.second;
            
            if (--top1.first > 0) {
                maxHeap.push(top1);
            }
            if (--top2.first > 0) {
                maxHeap.push(top2);
            }
        }
        
        if (!maxHeap.empty()) {
            if (maxHeap.top().first > 1) return "";
            result += maxHeap.top().second;
        }
        
        return result;
    }
};