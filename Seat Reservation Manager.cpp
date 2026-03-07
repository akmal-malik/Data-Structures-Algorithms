// Seat Reservation Manager (Heap | Medium)

// 🔍 Problem: Seat Reservation Manager
// 🔗 LeetCode Link: https://leetcode.com/problems/seat-reservation-manager/

/*
📝 Description:
Design a system that manages the reservation state of n seats numbered from 1 to n.

Implement the SeatManager class with the following functions:

1️⃣ SeatManager(int n)
   - Initializes the manager with n seats.
   - All seats are initially available.

2️⃣ int reserve()
   - Reserves the smallest-numbered available seat.
   - Returns the seat number.

3️⃣ void unreserve(int seatNumber)
   - Unreserves the given seat.
   - Makes the seat available again.

💡 Approach:
We use a Min Heap (priority queue) to always keep track of the smallest
available seat number.

- All seat numbers from 1 to n are pushed into the min heap initially.
- reserve() removes and returns the smallest seat number.
- unreserve() pushes the seat number back into the heap.

This ensures that the smallest available seat is always chosen.

⏱ Time Complexity:
Initialization → O(n log n)
reserve() → O(log n)
unreserve() → O(log n)

💾 Space Complexity:
O(n)
*/

#include <queue>
using namespace std;

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
