class Solution {
  public:
    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }

    long long catalan(int n) {
        if (n <= 1) return 1;
        long long num = factorial(2 * n);
        long long den = factorial(n + 1) * factorial(n);
        return num / den;
    }

    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Map each element to its number of BSTs when used as root
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int leftCount = i;
            int rightCount = n - i - 1;
            long long count = catalan(leftCount) * catalan(rightCount);
            mp[sortedArr[i]] = (int)count;
        }

        // Reconstruct result in original order
        vector<int> ans;
        for (int val : arr) {
            ans.push_back(mp[val]);
        }

        return ans;
    }
};
