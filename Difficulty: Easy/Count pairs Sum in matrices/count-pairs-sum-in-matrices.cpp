class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
          unordered_map<int, int> freq;
    int n = mat2.size();

    // Flatten mat2 and store frequencies
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            freq[mat2[i][j]]++;

    int count = 0;

    // Flatten mat1 and search for (x - mat1[i][j]) in mat2 using map
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int target = x - mat1[i][j];
            if (freq.find(target) != freq.end())
                count += freq[target];
        }

    return count;
    }
};