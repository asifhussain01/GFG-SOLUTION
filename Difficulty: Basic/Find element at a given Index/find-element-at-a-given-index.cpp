
class Solution {
  public:
    int findElementAtIndex(int key, vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size();i++){
            if(i == key){
                return arr[i];
            }
        }
    }
};
