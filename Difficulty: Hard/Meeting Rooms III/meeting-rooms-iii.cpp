//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
         sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        int maxi = 0, ans = 0;
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> initial;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
        for (int i = 0; i < n; i++) {
            initial.push({i, i});
        }
    
        for (auto &i : meetings) {
            int s = i[0], e = i[1];
            int empty;
    
            while (!pq.empty() && pq.top().first <= s) {
                empty = pq.top().second;
                pq.pop();
                initial.push({empty, empty});
            }
    
            if (!initial.empty()) {
                empty = initial.top().second;
                initial.pop();
                pq.push({e, empty});
                cnt[empty]++;
            } else {
                pair<int, int> temp = pq.top();
                pq.pop();
                int end_time = temp.first;
                empty = temp.second;
                int new_end = end_time + (e - s);
                pq.push({new_end, empty});
                cnt[empty]++;
            }
    
            if (cnt[empty] > maxi || (cnt[empty] == maxi && empty < ans)) {
                maxi = cnt[empty];
                ans = empty;
            }
        }
    
        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends