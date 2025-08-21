class Solution {
  public:
    // helper function to check if we can pick k elements 
    // with at least 'mid' difference
    bool canPlace(vector<int> &arr, int k, int mid) {
        int count = 1;  // pick first element
        int last = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= mid) {
                count++;
                last = arr[i];
                if (count >= k) return true;
            }
        }
        return false;
    }

    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int low = 0, high = arr.back() - arr.front(), ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canPlace(arr, k, mid)) {
                ans = mid;        // mid is possible, try bigger
                low = mid + 1;
            } else {
                high = mid - 1;   // mid not possible, try smaller
            }
        }
        
        return ans;
    }
};

