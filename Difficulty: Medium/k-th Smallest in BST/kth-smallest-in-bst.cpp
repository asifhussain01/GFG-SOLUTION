class Solution {
  public:
    void inorder(Node* root, int &k, int &ans) {
        if (root == NULL) return;
        
        inorder(root->left, k, ans);  // Visit left subtree
        
        k--;  // Decrease k after visiting a node
        if (k == 0) {  // If k becomes 0, we found our answer
            ans = root->data;
            return;
        }
        
        inorder(root->right, k, ans);  // Visit right subtree
    }
    
    int kthSmallest(Node *root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
