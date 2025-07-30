class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int currSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            currSum += arr[i];
            int needed = currSum - k;
            if (mpp.find(needed) != mpp.end()) {
                count += mpp[needed];
            }
            mpp[currSum]++;
        }

        return count;
    }
};