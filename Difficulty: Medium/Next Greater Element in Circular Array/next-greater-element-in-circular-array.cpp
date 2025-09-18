class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;  // stores indices

        // Traverse the array twice (simulate circular nature)
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Pop all elements smaller or equal to current
            while (!st.empty() && arr[st.top()] <= arr[idx]) {
                st.pop();
            }

            // If stack is not empty and we are in the first pass
            if (!st.empty() && i < n) {
                ans[idx] = arr[st.top()];
            }

            // Push current index
            st.push(idx);
        }

        return ans;
    }
};
