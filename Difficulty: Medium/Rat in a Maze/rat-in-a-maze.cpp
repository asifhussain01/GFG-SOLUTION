class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& maze, int n, 
               vector<string>& ans, string path, vector<vector<int>>& vis) {
        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Directions in lexicographical order: D, L, R, U
        // Down, Left, Right, Up
        string dir = "DLRU";
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            // Check boundaries and if the cell is valid
            if (ni >= 0 && nj >= 0 && ni < n && nj < n 
                && !vis[ni][nj] && maze[ni][nj] == 1) {
                
                vis[i][j] = 1;
                solve(ni, nj, maze, n, ans, path + dir[k], vis);
                vis[i][j] = 0; // backtrack
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();

        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) 
            return ans;  // No path possible

        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, maze, n, ans, "", vis);
        return ans;
    }
};
