class Solution {
  public:
  typedef long long ll;

// Function to calculate total cost for converting all towers to height 'target'
ll calculateCost(const vector<int>& heights, const vector<int>& cost, int target) {
    ll total = 0;
    for (int i = 0; i < heights.size(); ++i) {
        total += (ll)abs(heights[i] - target) * cost[i];
    }
    return total;
}
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
            int low = *min_element(heights.begin(), heights.end());
    int high = *max_element(heights.begin(), heights.end());
    ll ans = calculateCost(heights, cost, low);

    // Binary Search over possible target heights
    while (low < high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        ll cost1 = calculateCost(heights, cost, mid1);
        ll cost2 = calculateCost(heights, cost, mid2);

        ans = min(cost1, cost2);

        if (cost1 < cost2) {
            high = mid2 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return (int)ans;
    }
};
