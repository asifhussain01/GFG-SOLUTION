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
    int lengthOfLoop(Node *head) {
        if (!head || !head->next) return 0;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd’s algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { 
                // Step 2: Count length of loop
                return countLoopLength(slow);
            }
        }

        return 0; // No loop
    }

  private:
    int countLoopLength(Node* meetingPoint) {
        Node* temp = meetingPoint;
        int count = 1;

        while (temp->next != meetingPoint) {
            temp = temp->next;
            count++;
        }
        return count;
    }
};
