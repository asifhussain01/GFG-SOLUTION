class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true; // first level: left → right

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // find position to insert based on direction
                int index = leftToRight ? i : (size - i - 1);
                level[index] = node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // add current level to result
            for (int val : level)
                result.push_back(val);

            // toggle direction
            leftToRight = !leftToRight;
        }

        return result;
    }
};
