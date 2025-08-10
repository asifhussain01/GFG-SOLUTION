class Solution {
public:
    int countPS(string s) {
        int n = s.size();
        int count = 0;
        
        // Odd length palindromes
        for (int center = 0; center < n; center++) {
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) // length >= 2
                    count++;
                left--;
                right++;
            }
        }

        // Even length palindromes
        for (int center = 0; center < n - 1; center++) {
            int left = center, right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) // length >= 2
                    count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
