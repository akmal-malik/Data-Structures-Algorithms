// Problem: Linked list cycle 2
// ------------------------------------------------------------
// Problem Description:
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
// Note that pos is not passed as a parameter.
// Notice that you should not modify the linked list.
// ------------------------------------------------------------
// Approach: Floyd's Tortoise and Hare (Cycle Detection)
// Use two pointers, slow and fast. Slow moves one step at a time, while fast moves two steps. If there is a cycle, they will meet inside the cycle. To find the start of the cycle, reset one pointer to the head and move both pointers one step at a time until they meet again.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Finding the intersection point
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // If no cycle
        if (fast == nullptr || fast->next == nullptr) return nullptr;

        // Phase 2: Finding the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};