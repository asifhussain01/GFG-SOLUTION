class Solution {
  public:
    vector<int> search(string &pattern, string &text) {
        // code here.
         int d = 256; // character set size
        int q = 101; // a prime number for modulo hashing

        int m = pattern.length();
        int n = text.length();
        vector<int> result;

        if (m > n) return result;

        int h = 1;
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        int p = 0; // hash value for pattern
        int t = 0; // hash value for text

        // Initial hash computation
        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }

        for (int i = 0; i <= n - m; i++) {
            // If hash values match, check characters
            if (p == t) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    result.push_back(i + 1); // 1-based index
            }

            // Calculate hash for next window
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                if (t < 0)
                    t += q;
            }
        }

        return result;
    }
};