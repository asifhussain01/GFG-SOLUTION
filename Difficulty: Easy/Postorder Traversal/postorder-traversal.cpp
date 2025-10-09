class Solution {
  public:
    void helper(Node* root, vector<int> &ans) {
        if (!root) return;  // base case
        
        helper(root->left, ans);   // visit left subtree
        helper(root->right, ans);  // visit right subtree
        ans.push_back(root->data); // visit current node
    }
    
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
