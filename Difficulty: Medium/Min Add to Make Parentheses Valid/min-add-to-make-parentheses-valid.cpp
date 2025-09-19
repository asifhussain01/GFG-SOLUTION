class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;   // To count unmatched '('
        int close = 0;  // To count unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                open++;  // we have an extra '(' waiting for a ')'
            } else {
                if (open > 0) {
                    open--; // match this ')' with an earlier '('
                } else {
                    close++; // no '(' to match, so need an extra '('
                }
            }
        }
        
        // Total insertions needed = unmatched '(' + unmatched ')'
        return open + close;
    }
};
