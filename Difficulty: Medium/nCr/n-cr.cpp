//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
         if (r > n) return 0;

    long long res = 1;

    // C(n, r) = C(n, n - r)
    if (r > n - r)
        r = n - r;

    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return static_cast<int>(res);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends