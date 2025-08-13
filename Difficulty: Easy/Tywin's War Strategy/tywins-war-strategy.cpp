class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int required = (n + 1) / 2; // ceil(n/2)
        
        int lucky = 0;
        vector<int> cost;
        
        // Count lucky troops and store costs for making others lucky
        for (int x : arr) {
            if (x % k == 0) {
                lucky++;
            } else {
                cost.push_back(k - (x % k));
            }
        }
        
        // If already enough lucky troops
        if (lucky >= required) return 0;
        
        // Sort costs and pick smallest ones
        sort(cost.begin(), cost.end());
        int need = required - lucky;
        int total = 0;
        
        for (int i = 0; i < need; i++) {
            total += cost[i];
        }
        
        return total;
    }
};
