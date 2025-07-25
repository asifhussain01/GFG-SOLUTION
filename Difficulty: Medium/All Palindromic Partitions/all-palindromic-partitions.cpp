class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    // Recursive backtracking function to find all palindromic partitions
    void solve(int index, string &s, vector<string> &path, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, res);
                path.pop_back(); // backtrack
            }
        }
    }

    // Rename function to match GFG expected function name
    vector<vector<string>> palinParts(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0, s, path, res);
        return res;
    }
};