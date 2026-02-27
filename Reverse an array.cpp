#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Reverse an array in-place.
//
// Example:
// Input:  [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
//
// Approach:
// - Use two pointers:
//      left  -> start of array
//      right -> end of array
// - Swap elements at left and right
// - Move both pointers towards center
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    // Continue until both pointers meet
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    reverseArray(arr);

    // Print reversed array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
