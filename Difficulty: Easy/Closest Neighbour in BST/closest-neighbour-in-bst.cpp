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
}; */

class Solution {
  public:
  Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
    while (root != NULL) {
        if (root->data == k) {
            return k; // Exact match found
        }
        if (root->data < k) {
            ans = root->data; // Potential answer
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
    }
};