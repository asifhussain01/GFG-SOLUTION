class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        
        // Push all elements of queue into stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        
        // Pop from stack and push back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};
