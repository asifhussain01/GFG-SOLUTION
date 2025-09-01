class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq; // element -> frequency
        set<pair<int,int>> st;        // (-frequency, value) to get mode
        long long sum = 0;
        
        // Initialize first window
        for (int i = 0; i < k; i++) {
            int val = arr[i];
            if (freq.count(val)) {
                st.erase({-freq[val], val});
            }
            freq[val]++;
            st.insert({-freq[val], val});
        }
        
        // add mode of first window
        sum += st.begin()->second;
        
        // Slide the window
        for (int i = k; i < n; i++) {
            int outVal = arr[i - k];
            int inVal  = arr[i];
            
            // remove outgoing element
            st.erase({-freq[outVal], outVal});
            freq[outVal]--;
            if (freq[outVal] > 0)
                st.insert({-freq[outVal], outVal});
            
            // add incoming element
            if (freq.count(inVal) && freq[inVal] > 0) {
                st.erase({-freq[inVal], inVal});
            }
            freq[inVal]++;
            st.insert({-freq[inVal], inVal});
            
            // mode of current window
            sum += st.begin()->second;
        }
        
        return (int)sum;
    }
};
