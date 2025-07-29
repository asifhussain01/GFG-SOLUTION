class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
         unordered_map<char, pair<int, int>> charIndices;
        int n = s.size();

        // Step 1: Store first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (charIndices.find(s[i]) == charIndices.end()) {
                charIndices[s[i]].first = i;  // first occurrence
            }
            charIndices[s[i]].second = i;     // last occurrence
        }

        // Step 2: For each character with different first and last index, calculate ASCII sum
        vector<int> result;
        for (auto &[ch, range] : charIndices) {
            int start = range.first;
            int end = range.second;
            if (start < end - 1) { // strictly between
                int sum = 0;
                for (int i = start + 1; i < end; ++i) {
                    sum += s[i];
                }
                if (sum > 0) result.push_back(sum);
            }
        }

        return result;
    }
};