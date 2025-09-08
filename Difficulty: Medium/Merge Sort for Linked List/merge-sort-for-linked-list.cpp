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
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function to find the middle of linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;
        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge Sort function
    Node* mergeSort(Node* head) {
        // Base case: if head is null or only one node
        if (!head || !head->next) return head;

        // Find the middle node
        Node* mid = getMiddle(head);
        Node* rightHead = mid->next;
        mid->next = nullptr;  // Split list into two halves

        // Recursive calls for left and right halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        // Merge the sorted halves
        return merge(left, right);
    }
};
