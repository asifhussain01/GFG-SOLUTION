class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        
        // Store the last occurrence of each digit
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            // Try to find a larger digit than s[i], from right side
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;  // only one swap allowed
                }
            }
        }
        
        // Already lexicographically largest
        return s;
    }
};
