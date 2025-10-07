class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;

        // Map to store horizontal distance and the latest node at that distance
        map<int, int> hdNodeMap;  // {horizontal_distance -> node_data}

        // Queue for BFS traversal: stores pair of (node, horizontal distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // For bottom view, we overwrite the value at each horizontal distance
            hdNodeMap[hd] = node->data;

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Extract values in order of horizontal distance
        for (auto &p : hdNodeMap) {
            result.push_back(p.second);
        }

        return result;
    }
};
