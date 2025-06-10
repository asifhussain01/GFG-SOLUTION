
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        // code here
            vector<string> words;
    string word;
    stringstream ss(s);

    // Split words using stringstream (handles multiple spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the vector of words
    reverse(words.begin(), words.end());

    // Join words with a single space
    string result;
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1)
            result += ' ';
    }

    return result;
    }
};