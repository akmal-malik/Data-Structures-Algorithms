// Problem: Linked List (17 problems)
// ------------------------------------------------------------
// Problem Description:
// Given the head of a singly linked list, reverse the list and return the new head.
// ------------------------------------------------------------
// Approach: Iterative Reversal
// Traverse through the list and reverse the links between nodes iteratively.
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};