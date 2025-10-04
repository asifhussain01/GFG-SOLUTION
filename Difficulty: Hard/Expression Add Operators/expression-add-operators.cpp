class Solution {
  public:
    void helper(string &s, int target, int idx, long long currVal, long long prevVal, 
                string expr, vector<string> &res) {
        // Base case: reached end of string
        if (idx == s.size()) {
            if (currVal == target) res.push_back(expr);
            return;
        }
        
        // Try all possible splits
        for (int i = idx; i < s.size(); i++) {
            // Avoid numbers with leading zeros
            if (i != idx && s[idx] == '0') break;
            
            string part = s.substr(idx, i - idx + 1);
            long long num = stoll(part);
            
            if (idx == 0) {
                // First number, no operator before it
                helper(s, target, i + 1, num, num, part, res);
            } else {
                // Try '+'
                helper(s, target, i + 1, currVal + num, num, expr + "+" + part, res);
                
                // Try '-'
                helper(s, target, i + 1, currVal - num, -num, expr + "-" + part, res);
                
                // Try '*'
                helper(s, target, i + 1, currVal - prevVal + prevVal * num, prevVal * num, expr + "*" + part, res);
            }
        }
    }

    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        helper(s, target, 0, 0, 0, "", res);
        sort(res.begin(), res.end()); // for lexicographical order
        return res;
    }
};
