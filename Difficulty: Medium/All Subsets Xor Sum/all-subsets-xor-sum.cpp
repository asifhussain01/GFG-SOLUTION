class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        long long OR = 0;
        int n = arr.size();
        
        for (int x : arr)
            OR |= x;

        long long mul = 1LL << (n - 1);   // Use 1LL to avoid overflow

        long long ans = OR * mul;

        return (int)ans;
    }
};
