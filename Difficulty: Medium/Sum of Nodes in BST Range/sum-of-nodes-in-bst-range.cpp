class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // Base case
        if (root == NULL) return 0;

        int sum = 0;

        // If current node is within the range
        if (root->data >= l && root->data <= r)
            sum += root->data;

        // If current node's data is greater than l, 
        // then left subtree may have nodes within range
        if (root->data > l)
            sum += nodeSum(root->left, l, r);

        // If current node's data is less than r, 
        // then right subtree may have nodes within range
        if (root->data < r)
            sum += nodeSum(root->right, l, r);

        return sum;
    }
};
