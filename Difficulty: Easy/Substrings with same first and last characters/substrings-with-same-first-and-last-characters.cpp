//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
          int n = s.size(), cnt = 0;
        unordered_map<char, int> mp;
        for (int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        for (auto i: mp) {
            cnt += (i.second*(i.second+1))/2;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends