// Problem: Reverse nodes in k groups
// ------------------------------------------------------------
// Problem Description:
// Given a linked list, reverse the nodes of the list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the nodes, only nodes themselves may be changed.
// ------------------------------------------------------------
// Approach: Iterative
// The approach involves iterating through the list in groups of k nodes and reversing each group. 
// This is done by maintaining pointers to track the start and end of each group, and adjusting the 
// pointers to reverse the links within the group.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), as the solution uses a constant amount of extra space.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (true) {
            ListNode* groupEnd = prev->next;
            for (int i = 0; i < k; i++) {
                if (!groupEnd) return dummy.next;
                groupEnd = groupEnd->next;
            }
            
            ListNode* nextGroupStart = groupEnd->next;
            ListNode* prevNode = nextGroupStart;
            ListNode* currNode = prev->next;
            
            while (currNode != nextGroupStart) {
                ListNode* nextNode = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
            }
            
            ListNode* temp = prev->next;
            temp->next = nextGroupStart;
            prev->next = prevNode;
            prev = temp;
        }
    }
};