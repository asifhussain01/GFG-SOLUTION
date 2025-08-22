class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 1, high = 2000; // matrix values are between 1 and 2000
        int desired = (n * m + 1) / 2;
        int ans = -1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = 0;
            
            // Count how many elements <= mid using upper_bound in each row
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (cnt >= desired) {
                ans = mid;
                high = mid - 1;  // search smaller
            } else {
                low = mid + 1;   // search larger
            }
        }
        
        return ans;
    }
};
