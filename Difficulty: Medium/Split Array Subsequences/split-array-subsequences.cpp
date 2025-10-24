#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, end;
        
        // Step 1: Count frequencies of each number
        for (int num : arr)
            freq[num]++;
        
        // Step 2: Try to build subsequences
        for (int num : arr) {
            if (freq[num] == 0) continue; // already used
            
            freq[num]--; // use current number
            
            // Step 3: If there’s a subsequence ending with num-1, extend it
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            // Step 4: Otherwise, try to start a new subsequence of length k
            else {
                bool canForm = true;
                for (int i = 1; i < k; i++) {
                    if (freq[num + i] <= 0) {
                        canForm = false;
                        break;
                    }
                }
                if (!canForm) return false;
                
                // Use up next k-1 numbers
                for (int i = 1; i < k; i++)
                    freq[num + i]--;
                
                // This subsequence ends at num + k - 1
                end[num + k - 1]++;
            }
        }
        return true;
    }
};

