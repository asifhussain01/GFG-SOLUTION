#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[51][51][51];

    int solve(vector<vector<int>> &mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; // because r1 + c1 = r2 + c2

        // Base conditions
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;

        // Reached bottom-right cell
        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int result = mat[r1][c1];
        if (r1 != r2) // avoid double-counting if both in same cell
            result += mat[r2][c2];

        // Explore 4 possible moves (R,R), (R,D), (D,R), (D,D)
        int temp = max({
            solve(mat, r1 + 1, c1, r2 + 1), // both go down
            solve(mat, r1, c1 + 1, r2),     // first right, second right
            solve(mat, r1 + 1, c1, r2),     // first down, second right
            solve(mat, r1, c1 + 1, r2 + 1)  // first right, second down
        });

        result += temp;
        return dp[r1][c1][r2] = result;
    }

    int chocolatePickup(vector<vector<int>> &mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(mat, 0, 0, 0);
        return max(0, ans);
    }
};
