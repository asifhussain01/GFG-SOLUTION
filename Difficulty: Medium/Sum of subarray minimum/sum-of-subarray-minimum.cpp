class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
    vector<int> ple(n), nle(n);
    stack<int> st;
    
    // Previous Less Element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack for Next Less Element
    while (!st.empty()) st.pop();

    // Next Less Element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Calculate the result
    long long res = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        res = (res + (arr[i] * left % mod * right % mod)) % mod;
    }

    return res;
    }
};