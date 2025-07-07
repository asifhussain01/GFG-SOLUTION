class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
         int n = arr.size();
    vector<int> res(n, -1);     // Initialize result array with -1
    stack<int> st;              // Stack to store indices

    // Traverse the array twice (simulate circular array)
    for (int i = 2 * n - 1; i >= 0; --i) {
        int idx = i % n;

        // Maintain decreasing stack
        while (!st.empty() && arr[st.top()] <= arr[idx]) {
            st.pop();
        }

        // If stack is not empty, next greater element is on top
        if (!st.empty()) {
            res[idx] = arr[st.top()];
        }

        // Push current index
        st.push(idx);
    }

    return res;
    }
};