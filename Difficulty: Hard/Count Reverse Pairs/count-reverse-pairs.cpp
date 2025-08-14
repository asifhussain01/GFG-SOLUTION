class Solution {
  public:
  
    int mergeAndCount(vector<int> &arr, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }
  
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int count = mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += mergeAndCount(arr, low, mid, high);
        return count;
    }
  
    int countRevPairs(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
