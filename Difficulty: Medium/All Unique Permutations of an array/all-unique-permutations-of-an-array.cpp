#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        
        // Step 1: Sort to generate in lexicographic order
        sort(arr.begin(), arr.end());
        
        // Step 2: Generate all unique permutations
        do {
            result.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        
        return result;
    }
};
