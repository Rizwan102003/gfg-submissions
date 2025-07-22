class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n= arr.size();
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int i=1;
        while(mp.count(i)){
            i++;
        }
        
        return i;
    }
};