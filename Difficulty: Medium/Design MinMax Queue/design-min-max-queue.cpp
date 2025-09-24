#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    queue<int> q;
    deque<int> minDq, maxDq;

  public:

    // Insert element into the queue
    void enqueue(int x) {
        q.push(x);

        // Maintain monotonic increasing deque for min
        while (!minDq.empty() && minDq.back() > x) {
            minDq.pop_back();
        }
        minDq.push_back(x);

        // Maintain monotonic decreasing deque for max
        while (!maxDq.empty() && maxDq.back() < x) {
            maxDq.pop_back();
        }
        maxDq.push_back(x);
    }

    // Remove element from the queue
    void dequeue() {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        if (!minDq.empty() && minDq.front() == front) {
            minDq.pop_front();
        }
        if (!maxDq.empty() && maxDq.front() == front) {
            maxDq.pop_front();
        }
    }

    // Get front element
    int getFront() {
        return q.front();
    }

    // Get minimum element
    int getMin() {
        return minDq.front();
    }

    // Get maximum element
    int getMax() {
        return maxDq.front();
    }
};
