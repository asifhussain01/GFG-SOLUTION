class Solution {
  public:
    int maxPathSumUtil(Node* root, int &res) {
        if (root == NULL)
            return 0;

        // Recur for left and right subtrees
        int left = maxPathSumUtil(root->left, res);
        int right = maxPathSumUtil(root->right, res);

        // Ignore negative paths
        left = max(0, left);
        right = max(0, right);

        // Max path sum passing through the current node
        int currSum = root->data + left + right;

        // Update the result (global maximum)
        res = max(res, currSum);

        // Return max gain if continued up to parent
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
