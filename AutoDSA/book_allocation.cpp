// Problem: Book allocation
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers A where A[i] is the number of pages in the ith book. 
// There are M students. The task is to allocate books in such a way that each student gets at least one book and the number of pages assigned to a student is minimum.
// Each student can be assigned books from consecutive ranges only.
// ------------------------------------------------------------
// Approach: Binary Search
// Binary search for the minimum number of pages a student can have. 
// The lower bound is the maximum number of pages in a book, and the upper bound is the sum of all pages.
// For each mid value, check if it is possible to allocate books such that no student gets more than mid pages.
// If possible, try a smaller number of pages by adjusting the upper bound; otherwise, increase the lower bound.
// ------------------------------------------------------------
// Time Complexity: O(n log(sum(pages)))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& pages, int n, int m, int mid) {
        int student = 1;
        int pagesCount = 0;
        for(int i = 0; i < n; i++) {
            if(pages[i] > mid)
                return false;
            if(pagesCount + pages[i] > mid) {
                student++;
                pagesCount = pages[i];
                if(student > m)
                    return false;
            } else {
                pagesCount += pages[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int>& pages, int n, int m) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += pages[i];
        int ans = -1;
        int start = *max_element(pages.begin(), pages.end());
        int end = sum;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isPossible(pages, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};