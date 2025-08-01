class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        string vowels = "aeiou";
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                freq[ch]++;
            }
        }
        int count = 1, uniqueVowelCount = 0;
        for (char v : vowels) {
            if (freq.count(v)) {
                count *= freq[v];
                uniqueVowelCount++;
            }
        }
        if (uniqueVowelCount == 0) return 0;
        int fact = 1;
        for (int i = 2; i <= uniqueVowelCount; ++i) {
            fact *= i;
        }
        return count * fact;
    }
};