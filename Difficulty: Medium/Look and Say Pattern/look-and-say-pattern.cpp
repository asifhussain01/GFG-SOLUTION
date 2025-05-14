//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
          string s = "1";
        int row = 1;
        while (row<n) {
            string res; 
            for (int i=0; i<s.size();) {
                char ch = s[i];
                int cnt = 0;
                while (i<s.size() && s[i]==ch) {
                    cnt++;
                    i++;
                }
                res.push_back(cnt+'0');
                res.push_back(ch);
            } row++;
            s = res;
        } return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends