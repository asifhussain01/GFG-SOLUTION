//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
    vector<int> result(n);
    vector<int> left(n);
    vector<int> right(n);
    deque<int> dq;

    // Calculate left smaller element index
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        left[i] = dq.empty() ? -1 : dq.back();
        dq.push_back(i);
    }

    dq.clear();

    // Calculate right smaller element index
    for (int i = n - 1; i >= 0; --i) {
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        right[i] = dq.empty() ? n : dq.back();
        dq.push_back(i);
    }

    vector<int> ans(n + 1, INT_MIN);

    for (int i = 0; i < n; ++i) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for(int i = 0; i < n; i++){
        result[i] = ans[i+1];
    }
    return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends