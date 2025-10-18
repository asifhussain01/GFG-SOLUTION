class Solution {
  public:
    // Function to count nodes in BST
    int countNodes(Node* root) {
        int count = 0;
        Node* curr = root;
        while (curr) {
            if (!curr->left) {
                count++;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;
                    
                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
    }
    
    int findMedian(Node* root) {
        if (!root) return 0;

        int n = countNodes(root);
        int count = 0;
        Node* curr = root;
        Node* prev = nullptr;
        int median = 0;

        while (curr) {
            if (!curr->left) {
                count++;

                // Odd case: (n+1)/2th node
                if (n % 2 != 0 && count == (n + 1) / 2)
                    median = curr->data;

                // Even case: nth/2 node
                if (n % 2 == 0 && count == n / 2)
                    median = curr->data;

                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    count++;

                    if (n % 2 != 0 && count == (n + 1) / 2)
                        median = curr->data;

                    if (n % 2 == 0 && count == n / 2)
                        median = curr->data;

                    curr = curr->right;
                }
            }
        }
        return median;
    }
};
