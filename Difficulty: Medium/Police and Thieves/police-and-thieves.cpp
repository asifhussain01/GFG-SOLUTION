class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
    queue<int> police;
    queue<int> thieves;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            police.push(i);
        else if (arr[i] == 'T')
            thieves.push(i);

        // Try to pair the front of both queues
        while (!police.empty() && !thieves.empty()) {
            int pol = police.front();
            int thi = thieves.front();

            if (abs(pol - thi) <= k) {
                count++;
                police.pop();
                thieves.pop();
            } else {
                // Discard the one which is behind and too far
                if (thi < pol)
                    thieves.pop();
                else
                    police.pop();
            }
        }
    }
    return count;
    }
};