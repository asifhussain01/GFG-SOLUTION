class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if(n == 0) return;  // edge case
        k = k % n;          // effective rotations
        
        if(k == 0) return;  // no need to rotate
        
        if(type == 1) { 
            // Right rotation
            for(int i = 0; i < k; i++) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
        } else if(type == 2) { 
            // Left rotation
            for(int i = 0; i < k; i++) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};
