// Second Largest Element in an Array (Array | Easy)

// 🔍 Problem: Second Largest Element in an Array
// 🔗 GFG Link: https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        
        int largest = arr[0];
        int secondLargest = -1;

        // First pass: find the largest element
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        // Second pass: find the second largest element
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > secondLargest && arr[i] < largest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};
