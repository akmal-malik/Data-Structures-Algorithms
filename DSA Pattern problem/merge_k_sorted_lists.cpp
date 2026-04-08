// Problem: Merge k sorted lists
// ------------------------------------------------------------
// Problem Description:
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
// ------------------------------------------------------------
// Approach: Min-Heap
// Use a min-heap to keep track of the smallest element among the k lists. Each time, extract the smallest element and add it to the result list. Repeat until all elements are processed.
// ------------------------------------------------------------
// Time Complexity: O(N log k), where N is the total number of nodes across all lists.
// Space Complexity: O(k), for the min-heap.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            current->next = minNode;
            current = current->next;
            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        return dummyHead->next;
    }
};