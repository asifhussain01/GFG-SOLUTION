#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> minDq, maxDq;
        int left = 0, bestLen = 0, bestStart = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain max deque (decreasing order)
            while (!maxDq.empty() && arr[maxDq.back()] < arr[right])
                maxDq.pop_back();
            maxDq.push_back(right);

            // Maintain min deque (increasing order)
            while (!minDq.empty() && arr[minDq.back()] > arr[right])
                minDq.pop_back();
            minDq.push_back(right);

            // If difference > x, shrink from left
            while (!minDq.empty() && !maxDq.empty() &&
                   arr[maxDq.front()] - arr[minDq.front()] > x) {
                if (minDq.front() == left) minDq.pop_front();
                if (maxDq.front() == left) maxDq.pop_front();
                left++;
            }

            // Update best window
            int currLen = right - left + 1;
            if (currLen > bestLen) {
                bestLen = currLen;
                bestStart = left;
            }
        }

        // Return subarray
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};
