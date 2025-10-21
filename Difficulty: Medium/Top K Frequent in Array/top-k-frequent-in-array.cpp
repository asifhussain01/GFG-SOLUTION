class Solution {
public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Convert map to vector of pairs
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        // Sort by: frequency descending, then value descending
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first > b.first; // larger number first if same frequency
            return a.second > b.second; // higher frequency first
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
