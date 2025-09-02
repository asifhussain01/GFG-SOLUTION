/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Find length of list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // If k is invalid
        if (k > n) return head;

        // If kth from start and kth from end are same
        if (2 * k - 1 == n) return head;

        // Step 2: Find kth node from start
        Node* prevX = nullptr;
        Node* currX = head;
        for (int i = 1; i < k; i++) {
            prevX = currX;
            currX = currX->next;
        }

        // Step 3: Find kth node from end (n-k+1 from start)
        Node* prevY = nullptr;
        Node* currY = head;
        for (int i = 1; i < n - k + 1; i++) {
            prevY = currY;
            currY = currY->next;
        }

        // Step 4: Fix previous nodes' next pointers
        if (prevX) prevX->next = currY;
        else head = currY;

        if (prevY) prevY->next = currX;
        else head = currX;

        // Step 5: Swap next pointers
        Node* tmp = currX->next;
        currX->next = currY->next;
        currY->next = tmp;

        return head;
    }
};
