class Solution {
public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(currNum);
                stringStack.push(currStr);
                currNum = 0;
                currStr = "";
            }
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prev = stringStack.top(); stringStack.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++)
                    temp += currStr;

                currStr = prev + temp;
            }
            else {
                currStr += c;
            }
        }

        return currStr;
    }
};
