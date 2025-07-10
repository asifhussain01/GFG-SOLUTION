class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
            sort(words.begin(), words.end());  // Lexicographical sort
    unordered_set<string> s;
    string result = "";

    for (string &word : words) {
        // If word length is 1, or prefix exists in set
        if (word.length() == 1 || s.count(word.substr(0, word.length() - 1))) {
            s.insert(word);
            // Update result if longer, or same length but lexicographically smaller
            if (word.length() > result.length() || 
               (word.length() == result.length() && word < result)) {
                result = word;
            }
        }
    }
    return result;
    }
};