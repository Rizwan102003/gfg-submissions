class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
    int cand = 0;

    // Step 1: Find potential candidate
    for (int i = 1; i < n; i++) {
        if (mat[cand][i] == 1) {
            // cand knows i -> cand can't be celebrity
            cand = i;
        }
    }

    // Step 2: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            // Celebrity should not know i
            if (mat[cand][i] == 1) return -1;
            // Everyone should know celebrity
            if (mat[i][cand] == 0) return -1;
        }
    }
    return cand;
    }
};