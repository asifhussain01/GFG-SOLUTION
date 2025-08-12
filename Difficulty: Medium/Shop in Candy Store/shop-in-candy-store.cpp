class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        
        int minCost = 0, maxCost = 0;
        
        // Minimum cost
        int buy = 0, freeCandy = n - 1;
        while (buy <= freeCandy) {
            minCost += prices[buy];
            buy++;
            freeCandy -= k; // take k candies from the end for free
        }
        
        // Maximum cost
        buy = n - 1;
        freeCandy = 0;
        while (freeCandy <= buy) {
            maxCost += prices[buy];
            buy--;
            freeCandy += k; // take k candies from the start for free
        }
        
        return {minCost, maxCost};
    }
};
