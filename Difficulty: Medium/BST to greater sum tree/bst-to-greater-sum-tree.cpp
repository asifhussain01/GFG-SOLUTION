class Solution {
  public:
    int sum = 0; // to keep track of sum of greater nodes

    void transformTree(Node *root) {
        // perform reverse inorder traversal
        if (root == nullptr)
            return;

        // Step 1: traverse right subtree first
        transformTree(root->right);

        // Step 2: update current node
        int temp = root->data;
        root->data = sum;
        sum += temp;

        // Step 3: traverse left subtree
        transformTree(root->left);
    }
};
