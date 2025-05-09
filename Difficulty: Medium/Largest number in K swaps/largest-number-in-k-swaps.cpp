//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
   void findMax(string s, int k, string &maxNum, int idx) {
    if (k == 0) return;

    int n = s.length();
    char maxDigit = s[idx];

    // Find max digit from idx to end
    for (int i = idx + 1; i < n; i++) {
        if (s[i] > maxDigit)
            maxDigit = s[i];
    }

    // If maxDigit is not greater, no swap needed here
    if (maxDigit != s[idx]) k--;

    for (int i = n - 1; i >= idx; i--) {
        if (s[i] == maxDigit) {
            swap(s[idx], s[i]);
            if (s.compare(maxNum) > 0)
                maxNum = s;
            findMax(s, k, maxNum, idx + 1);
            swap(s[idx], s[i]); // backtrack
        }
    }
}

string findMaximumNum(string s, int k) {
    string maxNum = s;
    findMax(s, k, maxNum, 0);
    return maxNum;
}
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends