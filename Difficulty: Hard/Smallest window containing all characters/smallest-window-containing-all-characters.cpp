class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        // frequency arrays for lowercase letters
        vector<int> need(26, 0), have(26, 0);
        int required = 0; 

        // count characters in p
        for (char c : p) {
            if (need[c - 'a'] == 0) required++;
            need[c - 'a']++;
        }

        int l = 0, r = 0;
        int formed = 0;
        int minLen = INT_MAX, start = -1;

        while (r < s.size()) {
            char c = s[r];
            have[c - 'a']++;

            // check if this char count matches
            if (have[c - 'a'] == need[c - 'a']) {
                formed++;
            }

            // try shrinking window if all chars are matched
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // shrink from left
                char d = s[l];
                have[d - 'a']--;
                if (have[d - 'a'] < need[d - 'a']) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return (start == -1) ? "" : s.substr(start, minLen);
    }
};
