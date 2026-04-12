// Problem: Find Length of Linked List Cycle
// ------------------------------------------------------------
// Problem Description:
// Given a linked list, return the length of the cycle if the list contains a cycle. 
// If there is no cycle, return 0. There is a cycle in a linked list if there is some node in 
// the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node (0-indexed) in the linked list 
// where the cycle begins. If pos is -1, then there is no cycle in the linked list.
// ------------------------------------------------------------
// Approach: Floyd's Tortoise and Hare
// Use two pointers, slow and fast. Slow moves one step at a time, 
// while fast moves two steps at a time. If there is a cycle, 
// the two pointers will eventually meet inside the cycle. 
// To find the length of the cycle, move one pointer to the beginning 
// and then move both pointers one step at a time until they meet again. 
// The number of steps taken to meet again is the length of the cycle.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int detectCycleLength(ListNode* head) {
        if (!head || !head->next) return 0;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Detect if there is a cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        // If there is no cycle
        if (slow != fast) return 0;
        
        // Find the length of the cycle
        int length = 1;
        fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            length++;
        }
        
        return length;
    }
};