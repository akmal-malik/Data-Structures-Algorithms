// Problem: Reverse linked list 2
// ------------------------------------------------------------
// Problem Description:
// Reverse a linked list from position m to n. Do it in one-pass.
// 1 ≤ m ≤ n ≤ length of list.
// ------------------------------------------------------------
// Approach: Iterative with Dummy Node
// Use a dummy node to simplify edge cases and iterate through the list to reverse the sublist.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m == n) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        for (int i = 1; i < m; ++i) {
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode* nextTemp = curr->next;
            curr->next = nextTemp->next;
            nextTemp->next = prev->next;
            prev->next = nextTemp;
        }
        
        return dummy->next;
    }
};