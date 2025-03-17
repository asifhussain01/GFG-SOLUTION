//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public: 
    bool solve(vector<int>& arr, int sum,int i,vector<vector<int>>&dp){
        //base case 
        if(sum==0) return true;
        if(i==arr.size()) return false;
        //recursive case
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool pick=false,nopick=false;
        if(arr[i]<=sum) pick=solve(arr,sum-arr[i],i+1,dp);
        nopick=solve(arr,sum,i+1,dp);
        return dp[i][sum]= (pick || nopick);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
        
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends