class Solution {
  public:
    int moves = 0;
    
    // Helper function to calculate excess candies
    int dfs(Node* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        // Each move between nodes counts as abs(excess)
        moves += abs(left) + abs(right);
        
        // Return net candies that need to be passed to parent
        return root->data + left + right - 1;
    }

    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
