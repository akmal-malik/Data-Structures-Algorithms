// Maximum Frequency Stack (Stack + Hash Map | Hard)

// 🔍 Problem: Maximum Frequency Stack
// 🔗 LeetCode Link: https://leetcode.com/problems/maximum-frequency-stack/

/*
📝 Description:
Design a stack-like data structure that supports push and pop operations,
but when popping, it removes and returns the element with the highest frequency.

If multiple elements have the same highest frequency, the most recently
pushed element among them is removed first.

Implement the FreqStack class with the following operations:

1️⃣ FreqStack()
   - Initializes the frequency stack.

2️⃣ void push(int val)
   - Pushes an integer value onto the stack.

3️⃣ int pop()
   - Removes and returns the most frequent element.
   - If there is a tie in frequency, return the most recently pushed element.

💡 Approach:
We use two hash maps and a variable to track the maximum frequency.

1️⃣ freq map
   - Stores the frequency of each value.
   - Example: freq[val] = number of times val appears.

2️⃣ group map
   - Maps a frequency to a stack of elements having that frequency.
   - Example: group[f] stores elements whose frequency is f.

3️⃣ maxFreq
   - Keeps track of the current maximum frequency in the stack.

Push Operation:
- Increase the frequency of the value.
- Update maxFreq if needed.
- Push the value into the stack corresponding to its frequency.

Pop Operation:
- Get the top element from the stack with maxFreq.
- Remove it from the stack.
- Decrease its frequency.
- If the stack for maxFreq becomes empty, decrease maxFreq.

This ensures that:
✔ The most frequent element is popped first.
✔ If frequencies tie, the most recent element is returned.

⏱ Time Complexity:
push() → O(1)
pop() → O(1)

💾 Space Complexity:
O(n)
where n is the number of elements pushed into the stack.
*/
