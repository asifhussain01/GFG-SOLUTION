class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int total = 0, tank = 0, start = 0;

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            if (tank < 0) {
                start = i + 1;  // can't start from current or before
                tank = 0;       // reset current tank
            }
        }

        return (total >= 0) ? start : -1;
    }
};
