class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
                int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> result(n, -1);
        stack<int> st;

        // Step 1: Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Maintain elements with higher frequency in stack
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = arr[st.top()];
            }
            st.push(i);
        }

        return result;
    }
};
