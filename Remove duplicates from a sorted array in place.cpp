#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Remove duplicates from a sorted array in-place
// and return the new length of the array.
//
// Example:
// Input:  [1, 1, 2, 2, 3, 4, 4]
// Output: [1, 2, 3, 4]  (length = 4)
//
// Important:
// - The array is already SORTED.
// - We must modify it in-place.
// - Return the length of unique elements.
//
// Approach:
// - Use two pointers.
// - 'j' keeps track of last unique element.
// - Traverse with 'i'.
// - If nums[i] != nums[j], we found a new unique element.
// - Move j forward and update nums[j].
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

int removeDuplicates(vector<int>& nums) {

    // Edge case: empty array
    if (nums.empty())
        return 0;

    int j = 0;  // Points to last unique element

    for (int i = 1; i < nums.size(); i++) {

        // If current element is different,
        // it's a new unique element
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    // Length of unique elements
    return j + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int newLength = removeDuplicates(nums);

    cout << "Unique elements: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    cout << "\nNew Length: " << newLength;

    return 0;
}
