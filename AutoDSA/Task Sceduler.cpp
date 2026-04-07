// 🔥 Task Scheduler (LeetCode)
// Problem: Given tasks with cooldown n, find minimum CPU intervals required.

// 🧠 Approach:
// We use a greedy + mathematical approach instead of simulation.

// Key Observations:
// 1. The task with highest frequency determines the structure.
// 2. We try to arrange most frequent tasks first with gaps.
// 3. Fill remaining slots with other tasks or idle.

// Formula:
// Answer = max(total_tasks, (maxFreq - 1) * (n + 1) + maxCount)

// Where:
// maxFreq  -> highest frequency of any task
// maxCount -> number of tasks having maxFreq

// Example:
// tasks = [A,A,A,B,B,B], n = 2
// maxFreq = 3, maxCount = 2
// Answer = (3 - 1) * (2 + 1) + 2 = 8

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Step 1: Count frequency of each task (A-Z)
        vector<int> freq(26, 0);
        for(char t : tasks) {
            freq[t - 'A']++;
        }
        
        // Step 2: Find maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        
        // Step 3: Count how many tasks have this max frequency
        int maxCount = 0;
        for(int f : freq) {
            if(f == maxFreq) {
                maxCount++;
            }
        }
        
        // Step 4: Apply formula
        // Number of full blocks = maxFreq - 1
        int partCount = maxFreq - 1;
        
        // Each block size = cooldown + 1 (task + idle slots)
        int partLength = n + 1;
        
        // Minimum intervals required based on structure
        int minTime = partCount * partLength + maxCount;
        
        // Step 5: Final answer is max of:
        // - total tasks (if no idle needed)
        // - calculated structure (if idle needed)
        return max((int)tasks.size(), minTime);
    }
};
