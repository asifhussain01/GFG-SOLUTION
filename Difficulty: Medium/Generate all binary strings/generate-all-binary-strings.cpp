class Solution {
  public:
    vector<string> binstr(int n) {
        vector<string> ans;
        int total = 1 << n; // total combinations = 2^n
        
        for (int num = 0; num < total; num++) {
            string s = "";
            for (int i = n - 1; i >= 0; i--) {
                s += ((num >> i) & 1) ? '1' : '0';
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};
