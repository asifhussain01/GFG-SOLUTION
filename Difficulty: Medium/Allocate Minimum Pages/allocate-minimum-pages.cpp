//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   
   bool isPossible(vector<int>&arr, int k, int sol){
       int pageSum =0;
       int studentCount = 1;
       for(int i = 0; i<arr.size(); i++){
           if(arr[i] > sol){
               return false;
           }
           if(pageSum + arr[i] > sol){
               studentCount++;
               pageSum = arr[i];
               if(studentCount > k){
                   return false;
               }
           }
           else{
               pageSum += arr[i];
           }
       }
       return true;
   }
   
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int start =0;
        int end = accumulate(arr.begin(), arr.end(), 0);
        int N = arr.size();
        int ans =-1;
        
        if(N < k)return -1;
        
        while(start <= end){
            int mid = start +(end - start)/2;
            
            if(isPossible(arr, k, mid)){
                ans = mid;
                end = mid -1;
                
            }
            else{
                start= mid+1;
            }
        }
        return ans;
    }

    
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends