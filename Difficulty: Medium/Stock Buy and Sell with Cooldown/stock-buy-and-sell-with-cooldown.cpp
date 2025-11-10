class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int hold = -arr[0];     // profit when holding a stock
        int sold = 0;           // profit when just sold a stock
        int cooldown = 0;       // profit when in cooldown

        for (int i = 1; i < n; i++) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_cooldown = cooldown;

            // If we hold today, either we already held or we buy today (after cooldown)
            hold = max(prev_hold, prev_cooldown - arr[i]);

            // If we sold today, we must have held stock before
            sold = prev_hold + arr[i];

            // If we are in cooldown today, either we were already in cooldown or sold yesterday
            cooldown = max(prev_cooldown, prev_sold);
        }

        // The answer will be the max of sold or cooldown (can't end while holding a stock)
        return max(sold, cooldown);
    }
};
