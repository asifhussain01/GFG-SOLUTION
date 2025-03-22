//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int i,int n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=arr[i]+solve(arr,i+2,n,dp);
        int nopick=solve(arr,i+1,n,dp);
        return dp[i]= max(pick,nopick);
    }
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int case1=solve(arr,0,n-1,dp);
        fill(dp.begin(),dp.end(),-1);
        int case2=solve(arr,1,n,dp);
        return max(case1,case2);
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends