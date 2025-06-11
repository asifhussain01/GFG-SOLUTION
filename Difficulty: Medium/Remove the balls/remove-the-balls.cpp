class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st;  // Stack to hold (color, radius)

    for (int i = 0; i < color.size(); ++i) {
        if (!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
            // Same color and radius as top => remove both
            st.pop();
        } else {
            // Otherwise, push current ball onto stack
            st.push({color[i], radius[i]});
        }
    }

    return st.size();
    }
};