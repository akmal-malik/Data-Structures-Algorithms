// Problem: Merge two sorted lists
// ------------------------------------------------------------
// Problem Description:
// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
// ------------------------------------------------------------
// Approach: Iterative Merging
// Traverse both lists and insert the smaller value at the end of the merged list.
// ------------------------------------------------------------
// Time Complexity: O(n + m), where n and m are the lengths of the two lists.
// Space Complexity: O(1) as no extra space is used.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != NULL) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        return dummy->next;
    }
};