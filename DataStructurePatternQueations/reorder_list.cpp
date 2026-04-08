// Problem: Reorder list
// ------------------------------------------------------------
// Problem Description:
// Reorder the given linked list in-place such that first half of the list is followed by the reversed second half.
// The first node of the linked list should remain unchanged, and you should reorder the nodes.
// The solution should not be in O(n log n) time complexity.
// ------------------------------------------------------------
// Approach: Two-Pointer and Stack
// Use two pointers to find the middle of the linked list and then use a stack to reverse the second half.
// After that, merge the first half and the reversed second half.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        stack<ListNode*> st;
        ListNode* current = slow;
        while (current) {
            st.push(current);
            current = current->next;
        }

        // Merge the first half and the reversed second half
        current = head;
        while (!st.empty()) {
            ListNode* temp = st.top();
            st.pop();
            temp->next = current->next;
            current->next = temp;
            current = temp->next->next;
        }

        // Set the next of the last node to NULL
        if (current) current->next = NULL;
    }
};