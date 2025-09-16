#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (string &token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                long long res = 0;
                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = 1LL * a * b;
                else if (token == "/") {
                    int q = a / b;
                    int r = a % b;
                    if ((r != 0) && ((a < 0) ^ (b < 0))) q--;
                    res = q;
                }
                else if (token == "^") res = pow(a, b);
                st.push((int)res);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
