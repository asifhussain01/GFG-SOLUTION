class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // stable_sort keeps original order if abs diff is same
        stable_sort(arr.begin(), arr.end(),
            [x](int a, int b) {
                return abs(a - x) < abs(b - x);
            }
        );
    }
};
