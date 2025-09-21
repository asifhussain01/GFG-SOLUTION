class Solution {
  public:
    // Function to calculate the largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size(), m = mat[0].size();
        vector<int> heights(m, 0);
        int maxRect = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Build histogram heights
                if (mat[i][j] == 0)
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            // Get largest rectangle for this row's histogram
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};
