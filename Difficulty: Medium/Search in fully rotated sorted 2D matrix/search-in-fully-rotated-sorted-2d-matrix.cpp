class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int l = 0, r = n * m - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mat[mid / m][mid % m];
            int leftVal = mat[l / m][l % m];
            int rightVal = mat[r / m][r % m];
            
            if (midVal == x) return true;
            
            // Left half is sorted
            if (leftVal <= midVal) {
                if (x >= leftVal && x < midVal) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (x > midVal && x <= rightVal) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        return false;
    }
};
