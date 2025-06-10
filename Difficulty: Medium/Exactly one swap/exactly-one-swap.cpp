class Solution {
public:
    int countStrings(string& s) {
        int n = s.length();

        vector<int> mp(26, 0);         // frequency array for lowercase letters
        int         result = 0;

        for (int i = 0; i < n; i++) {
            result += (i - mp[s[i] - 'a']);   // count swaps with different chars seen so far
            mp[s[i] - 'a']++;                 // increment frequency of current character
        }

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 1) {         // check if any character has duplicate
                result++;            // if yes, add one for swap that returns same string
                break;
            }
        }

        return result;
    }
};