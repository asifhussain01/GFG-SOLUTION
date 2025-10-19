class Solution {
  public:
    void inorder(Node* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> nodes;
        inorder(root, nodes);  // get sorted BST values
        
        // Custom comparator for sorting by closeness, then by smaller value
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            int diffA = abs(a - target);
            int diffB = abs(b - target);
            if (diffA == diffB) return a < b;
            return diffA < diffB;
        });
        
        // Pick first k values
        vector<int> result;
        for (int i = 0; i < k && i < (int)nodes.size(); i++) {
            result.push_back(nodes[i]);
        }
        
        return result;
    }
};
