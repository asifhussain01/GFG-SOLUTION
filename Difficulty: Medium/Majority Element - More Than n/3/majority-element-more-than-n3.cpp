class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        // Code here
               int n = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

        // First pass to find potential candidates
        for (int num : nums) {
            if (num == num1) {
                count1++;
            } else if (num == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass to verify the candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == num1) count1++;
            else if (num == num2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(num1);
        if (count2 > n / 3) result.push_back(num2);
        sort(result.begin(), result.end());
        return result;
    }
};