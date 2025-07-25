/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
     bool isMirror(Node* t1, Node* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        
        return (t1->data == t2->data) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(Node* root) {
        // Code here
        return isMirror(root, root);
    }
};