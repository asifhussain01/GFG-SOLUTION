/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k == 1) return head;

        // Count total nodes
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        Node* newHead = NULL;    // will be returned as final head
        Node* prevTail = NULL;   // tail of previous reversed group
        Node* curr = head;

        while (length > 0) {
            int groupSize = (length >= k ? k : length);  // if remaining < k, still reverse
            Node* prev = NULL;
            Node* next = NULL;
            Node* groupHead = curr;   // current group's head (will become tail after reverse)

            int count = 0;
            while (curr && count < groupSize) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            // set newHead for the first group
            if (!newHead) {
                newHead = prev;
            }

            // connect previous group's tail to current group's head
            if (prevTail) {
                prevTail->next = prev;
            }

            // update prevTail to this group's tail (which is groupHead)
            prevTail = groupHead;

            length -= groupSize;
        }

        return newHead;
    }
};
