class Solution {
  public:
    static bool cmp(string &a, string &b) {
        return a + b > b + a;  // Compare concatenated results
    }

    string findLargest(vector<int> &arr) {
        vector<string> nums;
        
        // Convert all integers to strings
        for (int x : arr) {
            nums.push_back(to_string(x));
        }
        
        // Sort with custom comparator
        sort(nums.begin(), nums.end(), cmp);
        
        // Edge case: if the largest is "0", return "0"
        if (nums[0] == "0") return "0";
        
        // Concatenate result
        string result = "";
        for (string &s : nums) {
            result += s;
        }
        
        return result;
    }
};
