class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& A, vector<int>& B, int K) {
        // code here
         int N = A.size();
    
    // Sort both arrays in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Max heap to store {sum, {i, j}} pairs
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> visited;

    // Initial combination: largest elements from both arrays
    maxHeap.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});

    vector<int> result;

    while (K-- && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();

        result.push_back(top.first);

        int i = top.second.first;
        int j = top.second.second;

        // Next possible pair (i+1, j)
        if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
            maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        // Next possible pair (i, j+1)
        if (j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
            maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return result;
    }
};