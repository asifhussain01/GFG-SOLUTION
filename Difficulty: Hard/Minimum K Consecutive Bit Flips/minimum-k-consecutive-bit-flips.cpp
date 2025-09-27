class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0); // marks if flip started at i
        int flip = 0;   // current parity of flips (0=even, 1=odd)
        int count = 0;  // number of flips performed

        for (int i = 0; i < n; i++) {
            // If we are past i-k, remove old flip effect
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }

            // If current bit (after flips) is 0, we must flip here
            if ((arr[i] ^ flip) == 0) {
                if (i + k > n) return -1; // not enough space to flip
                isFlipped[i] = 1; // start flip at i
                flip ^= 1;        // toggle flip parity
                count++;
            }
        }
        return count;
    }
};
