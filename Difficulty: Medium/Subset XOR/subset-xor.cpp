class Solution {
public:
    vector<int> subsetXOR(int n) {
        int totalXOR = 0;
        
        // Compute XOR from 1 to n
        // XOR from 1..n follows pattern: n,1,n+1,0 (based on n%4)
        if (n % 4 == 1) totalXOR = 1;
        else if (n % 4 == 2) totalXOR = n + 1;
        else if (n % 4 == 3) totalXOR = 0;
        else totalXOR = n;

        int x = totalXOR ^ n;

        vector<int> ans;

        if (x >= 1 && x <= n) {
            // remove x → gives lexicographically smallest of size n-1
            for (int i = 1; i <= n; i++)
                if (i != x) ans.push_back(i);
        } else {
            // cannot remove x → use full set
            for (int i = 1; i <= n; i++)
                ans.push_back(i);
        }

        return ans;
    }
};

