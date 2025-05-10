//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
    vector<int> mapped(n);

    // Step 1: Map array elements to +1 or -1
    for (int i = 0; i < n; ++i) {
        mapped[i] = (arr[i] > k) ? 1 : -1;
    }

    // Step 2: Prefix sum with hashmap
    unordered_map<int, int> firstOccurrence;
    int maxLen = 0, prefixSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += mapped[i];

        if (prefixSum > 0) {
            maxLen = i + 1;  // whole array till i is valid
        } else {
            if (firstOccurrence.find(prefixSum - 1) != firstOccurrence.end()) {
                maxLen = max(maxLen, i - firstOccurrence[prefixSum - 1]);
            }
        }

        if (firstOccurrence.find(prefixSum) == firstOccurrence.end()) {
            firstOccurrence[prefixSum] = i;
        }
    }

    return maxLen;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends