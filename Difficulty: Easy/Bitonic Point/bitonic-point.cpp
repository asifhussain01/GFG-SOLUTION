//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
          int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the bitonic point
        if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
            (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
            return arr[mid];
        }
        // If the mid element is less than the next element,
        // then the peak lies to the right
        else if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
        // Else, the peak lies to the left
        else {
            right = mid - 1;
        }
    }

    // Should never reach here if the input is valid
    return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends