class Solution {
  public:
    string caseSort(string& s) {
        // code here
            vector<char> upper, lower;

    // Separate characters by case
    for (char c : s) {
        if (isupper(c)) upper.push_back(c);
        else lower.push_back(c);
    }

    // Sort each group
    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());

    // Merge maintaining original case positions
    int u = 0, l = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i]))
            s[i] = upper[u++];
        else
            s[i] = lower[l++];
    }

    return s;

    }
};