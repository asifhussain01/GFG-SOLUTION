/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* constructTreeUtil(vector<int> &pre, vector<int> &post, int &preIndex, int l, int r, unordered_map<int,int> &postMap) {
        // Base condition
        if (preIndex >= pre.size() || l > r)
            return nullptr;
        
        // Create root node
        Node* root = new Node(pre[preIndex++]);
        
        // If this node is a leaf, return it
        if (l == r || preIndex >= pre.size())
            return root;
        
        // Find the next preorder element in postorder to split left subtree
        int postIndex = postMap[pre[preIndex]];
        
        // If valid index found, build left and right subtrees
        if (postIndex <= r) {
            root->left = constructTreeUtil(pre, post, preIndex, l, postIndex, postMap);
            root->right = constructTreeUtil(pre, post, preIndex, postIndex + 1, r - 1, postMap);
        }
        
        return root;
    }

    Node* constructTree(vector<int> &pre, vector<int> &post) {
        unordered_map<int,int> postMap;
        int n = post.size();
        
        // Store postorder value -> index for quick lookup
        for (int i = 0; i < n; i++)
            postMap[post[i]] = i;
        
        int preIndex = 0;
        return constructTreeUtil(pre, post, preIndex, 0, n - 1, postMap);
    }
};
