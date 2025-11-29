class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // largest power of 2 <= n
        int x = log2(n);
        int powerOf2 = 1 << x;

        // 1. count of set bits from 1 to 2^x - 1
        int bitsUptoPower = x * (powerOf2 >> 1);

        // 2. MSB set bits from 2^x to n
        int msbBits = n - powerOf2 + 1;

        // 3. Recurse for remaining numbers
        int rest = countSetBits(n - powerOf2);

        return bitsUptoPower + msbBits + rest;
    }
};

