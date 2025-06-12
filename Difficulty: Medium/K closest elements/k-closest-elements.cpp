class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        vector<pair<int, int>> diffArr;

        // Build pairs of (absolute difference, element), excluding x itself
        for (int num : arr) {
            if (num != x) {
                diffArr.push_back({abs(num - x), num});
            }
        }

        // Sort using custom rule: if diff equal, prefer larger number
        sort(diffArr.begin(), diffArr.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        // Collect first k elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(diffArr[i].second);
        }

        return result;
    }
};