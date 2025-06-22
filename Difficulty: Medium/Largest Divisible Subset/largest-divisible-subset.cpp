class Solution {
  public:
    vector<int> solve(vector<int>& arr, int i, int prev, map<pair<int, int>, vector<int>>& dp) {
        if (i >= arr.size()) return {};

        pair<int, int> key = {i, prev};
        if (dp.find(key) != dp.end()) return dp[key];

        // Option 1: skip current element
        vector<int> notTake = solve(arr, i + 1, prev, dp);

        // Option 2: take current element if divisible
        vector<int> take;
        if (prev == -1 || arr[i] % prev == 0) {
            take = solve(arr, i + 1, arr[i], dp);
            take.insert(take.begin(), arr[i]); // add arr[i] to front
        }

        // Choose the longer subset
        if (take.size() > notTake.size())
            return dp[key] = take;
        else
            return dp[key] = notTake;
    }

    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<pair<int, int>, vector<int>> dp;
        return solve(arr, 0, -1, dp); // -1 means no previous element
    }
};