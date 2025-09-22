class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Step 1: Find Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Step 2: Find Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Step 3: Initialize result array (1-based indexing for window size)
        vector<int> res(n + 1, 0);

        // Step 4: For each element, find window length where it's minimum
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Step 5: Fill remaining entries (propagate from right to left)
        for (int i = n - 1; i >= 1; i--)
            res[i] = max(res[i], res[i + 1]);

        // Step 6: Remove the dummy 0th index and return result
        res.erase(res.begin());
        return res;
    }
};
