class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
               string filtered = "";

        // Step 1: Filter only alphanumeric and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Step 2: Check if the filtered string is a palindrome
        int left = 0;
        int right = filtered.size() - 1;

        while (left < right) {
            if (filtered[left] != filtered[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};