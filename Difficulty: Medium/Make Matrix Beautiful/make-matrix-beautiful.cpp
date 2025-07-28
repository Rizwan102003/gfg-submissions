class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int row_sum = 0, col_sum = 0;
        int max_sum = 0, total = 0;

        for (int i = 0; i < n; i++) {
            row_sum = 0;
            col_sum = 0;
            for (int j = 0; j < n; j++) {
                row_sum += mat[i][j];
                col_sum += mat[j][i];
            }
            max_sum = max({max_sum, row_sum, col_sum});
            total += row_sum;
        }
        
        return (n * max_sum) - total; 
    }
};