class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
          int n = s.length();
    long long result = 0, prev = 0;
    int mod = 1000000007; // Not needed if we assume it fits in 32-bit int

    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        prev = prev * 10 + num * (i + 1);
        result += prev;
    }

    return result;
    }
};