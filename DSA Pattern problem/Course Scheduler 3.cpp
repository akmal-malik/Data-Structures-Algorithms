// 🔥 Course Schedule III (LeetCode)

// 🧠 Problem:
// Each course = [duration, lastDay]
// You must complete the course before lastDay
// Only one course at a time
// Return maximum number of courses you can take

// 🚀 Approach: Greedy + Max Heap

// 💡 Key Idea:
// 1. Always try to take courses with earlier deadlines first
// 2. Keep track of total time spent
// 3. If we exceed a deadline:
//    → Remove the course with the longest duration (worst choice)

// Why remove longest?
// Because removing the longest frees maximum time → better chance to fit more courses

// 🧩 Steps:
// 1. Sort courses by lastDay (ascending)
// 2. Iterate through courses:
//    - Add duration to total time
//    - Push duration into max heap
//    - If time exceeds lastDay:
//        → remove the longest duration course

// 🧠 Example:
// courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
//
// After sorting by lastDay:
// [[100,200],[1000,1250],[200,1300],[2000,3200]]
//
// Process:
// time = 100 → ok
// time = 1100 → ok
// time = 1300 → ok
// time = 3300 → exceeds → remove 2000 → time = 1300
//
// Answer = 3

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        // Step 1: Sort by deadline
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Max heap to store durations of selected courses
        priority_queue<int> maxHeap;
        
        int time = 0; // total time spent
        
        // Step 2: Iterate over courses
        for(auto &course : courses){
            int duration = course[0];
            int lastDay = course[1];
            
            // Take the course
            time += duration;
            maxHeap.push(duration);
            
            // Step 3: If deadline exceeded → remove longest course
            if(time > lastDay){
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        // Step 4: Number of courses taken
        return maxHeap.size();
    }
};
