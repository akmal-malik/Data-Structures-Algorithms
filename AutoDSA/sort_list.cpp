// Problem: Sort List
// ------------------------------------------------------------
// Problem Description:
// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
// ------------------------------------------------------------
// Approach: Insertion Sort
// Iterate through the list, and for each node, insert it into its correct position in the sorted portion of the list.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the number of nodes in the list.
// Space Complexity: O(1), as the sorting is done in-place.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* temp;

        while (curr) {
            if (prev->val <= curr->val) {
                prev = curr;
                curr = curr->next;
            } else {
                temp = dummy;
                while (temp->next->val <= curr->val) {
                    temp = temp->next;
                }
                prev->next = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                curr = prev->next;
            }
        }

        return dummy->next;
    }
};