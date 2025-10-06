class Solution {
  public:
    // Directions a Knight can move
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }

    bool solve(int x, int y, int moveCount, int n, vector<vector<int>>& board) {
        // If all squares are visited
        if (moveCount == n * n)
            return true;
        
        // Try all 8 possible moves
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (isSafe(nx, ny, n, board)) {
                board[nx][ny] = moveCount;
                if (solve(nx, ny, moveCount + 1, n, board))
                    return true;
                // Backtrack
                board[nx][ny] = -1;
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        
        // Starting position
        board[0][0] = 0;
        
        // Start from (0, 0) with step 1
        if (solve(0, 0, 1, n, board))
            return board;
        else
            return {};
    }
};
