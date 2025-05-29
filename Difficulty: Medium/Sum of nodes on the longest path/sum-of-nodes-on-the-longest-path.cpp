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
    void findLongestPath(Node* root, int currentLen, int currentSum, int &maxLen, int &maxSum) {
    if (!root) return;

    currentLen += 1;
    currentSum += root->data;

    // Check if it's a leaf node
    if (!root->left && !root->right) {
        if (currentLen > maxLen) {
            maxLen = currentLen;
            maxSum = currentSum;
        } else if (currentLen == maxLen) {
            maxSum = max(maxSum, currentSum);
        }
    }

    findLongestPath(root->left, currentLen, currentSum, maxLen, maxSum);
    findLongestPath(root->right, currentLen, currentSum, maxLen, maxSum);
}

// Main function
int sumOfLongRootToLeafPath(Node* root) {
    int maxLen = 0, maxSum = 0;
    findLongestPath(root, 0, 0, maxLen, maxSum);
    return maxSum;
}
};