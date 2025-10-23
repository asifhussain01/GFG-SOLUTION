#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to store the k closest points based on distance
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        
        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y; // squared distance from origin
            
            // push current point
            maxHeap.push({dist, {x, y}});
            
            // if size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // extract k closest points
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            auto point = maxHeap.top().second;
            maxHeap.pop();
            result.push_back({point.first, point.second});
        }
        
        return result; // order doesn’t matter
    }
};


