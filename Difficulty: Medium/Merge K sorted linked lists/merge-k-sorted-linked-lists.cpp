class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap by data
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        // Push the head of every linked list into the heap
        for (auto head : arr) {
            if (head != NULL) {
                pq.push(head);
            }
        }

        // Dummy node to simplify result building
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Extract the smallest element one by one
        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
