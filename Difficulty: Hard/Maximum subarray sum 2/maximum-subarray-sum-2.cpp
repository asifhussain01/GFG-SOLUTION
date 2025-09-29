class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        
        // Step 1: Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        long long ans = LLONG_MIN;
        deque<int> dq; // will store indices of prefix sums
        
        // Step 2: Iterate over end index
        for (int i = a; i <= n; i++) {
            // Remove indices from front that are out of current window (i - b)
            while (!dq.empty() && dq.front() < i - b)
                dq.pop_front();
            
            // Add index (i - a) — this index can now be used as start
            int idx = i - a;
            while (!dq.empty() && prefix[dq.back()] >= prefix[idx])
                dq.pop_back();
            dq.push_back(idx);
            
            // Now, calculate possible max sum
            if (!dq.empty()) {
                ans = max(ans, prefix[i] - prefix[dq.front()]);
            }
        }
        
        return (int)ans;
    }
};
