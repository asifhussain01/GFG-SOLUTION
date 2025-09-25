#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        result.reserve(n);

        queue<string> q;
        q.push("1");

        for (int i = 0; i < n; ++i) {
            string s = q.front();
            q.pop();

            result.push_back(s);

            // generate next two binary numbers
            q.push(s + "0");
            q.push(s + "1");
        }

        return result;
    }
};
