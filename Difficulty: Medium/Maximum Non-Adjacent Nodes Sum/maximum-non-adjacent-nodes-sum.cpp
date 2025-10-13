class Solution {
    unordered_map<Node*, int> dp;

public:
    int getMaxSum(Node* root) {
        if (!root) return 0;
        if (dp[root]) return dp[root];

        // Include current node
        int include = root->data;
        if (root->left)
            include += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        if (root->right)
            include += getMaxSum(root->right->left) + getMaxSum(root->right->right);

        // Exclude current node
        int exclude = getMaxSum(root->left) + getMaxSum(root->right);

        return dp[root] = max(include, exclude);
    }
};
