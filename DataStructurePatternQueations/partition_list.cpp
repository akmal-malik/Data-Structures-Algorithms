// Problem: Partition list
// ------------------------------------------------------------
// Problem Description:
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
// ------------------------------------------------------------
// Approach: Two-Pointer Technique
// Use two pointers to create two separate lists: one for nodes less than x and another for nodes greater than or equal to x. Traverse the original list and append each node to the appropriate list. Finally, concatenate the two lists.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0);
        ListNode* dummyGreaterEqual = new ListNode(0);
        ListNode* less = dummyLess;
        ListNode* greaterEqual = dummyGreaterEqual;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greaterEqual->next = head;
                greaterEqual = greaterEqual->next;
            }
            head = head->next;
        }

        greaterEqual->next = nullptr;
        less->next = dummyGreaterEqual->next;

        return dummyLess->next;
    }
};