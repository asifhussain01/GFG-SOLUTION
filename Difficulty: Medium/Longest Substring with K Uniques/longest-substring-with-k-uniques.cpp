class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         int n = s.length();
    if (n == 0 || k == 0) return -1;

    unordered_map<char, int> freq;
    int maxLen = -1, left = 0;

    for (int right = 0; right < n; ++right) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        if (freq.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
    }
};