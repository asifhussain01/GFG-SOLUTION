class Solution {
  public:
  
    bool canEatAll(vector<int>& piles, int k, int speed) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + speed - 1) / speed; // ceil(pile / speed)
        }
        return totalHours <= k;
    }
    
    int kokoEat(vector<int>& piles, int k) {
        // Code here
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};