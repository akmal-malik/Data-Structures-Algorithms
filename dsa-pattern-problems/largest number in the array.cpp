// Largest Element in an Array (Array | Easy)

// 🔍 Problem: Largest Element in an Array
// 🔗 GFG Link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

class Solution {
public:
    int largest(vector<int> &arr) {
        int maxElement = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }

        return maxElement;
    }
};
