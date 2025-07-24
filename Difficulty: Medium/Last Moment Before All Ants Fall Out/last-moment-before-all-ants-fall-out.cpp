class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
         int maxTime = 0;

        // For ants moving to the left, max time = their position
        for (int pos : left) {
            maxTime = max(maxTime, pos);
        }

        // For ants moving to the right, max time = n - their position
        for (int pos : right) {
            maxTime = max(maxTime, n - pos);
        }

        return maxTime;
    }
};