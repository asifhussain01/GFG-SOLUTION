class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            int area = width * height;
            maxArea = max(maxArea, area);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
