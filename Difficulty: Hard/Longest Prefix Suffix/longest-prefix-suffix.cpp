class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0); // LPS array

        int len = 0; // length of the previous longest prefix suffix
        int i = 1;   // start from the second character

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1]; // last value is the answer
    }
};
