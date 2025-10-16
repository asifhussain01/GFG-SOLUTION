class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // Base case
        if (root == NULL)
            return NULL;
        
        // First, fix the left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        // Now handle the current node
        if (root->data < l) {
            // Node is smaller than range — discard left subtree
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }
        else if (root->data > r) {
            // Node is greater than range — discard right subtree
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }
        
        // Node is in range — keep it
        return root;
    }
};
