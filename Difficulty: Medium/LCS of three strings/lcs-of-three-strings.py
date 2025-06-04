class Solution:
    def lcsOf3(self,s1, s2, s3):
        # Code here
        n1, n2, n3 = len(s1), len(s2), len(s3)
    
        
        dp = [[[0]*(n3+1) for _ in range(n2+1)] for _ in range(n1+1)]
        for i in range(n1):
            for j in range(n2):
                for k in range(n3):
                    if s1[i] == s2[j] == s3[k]:
                        dp[i+1][j+1][k+1] = dp[i][j][k] + 1
                    else:
                        dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], dp[i][j+1][k+1], dp[i+1][j][k+1])
        
        return dp[n1][n2][n3]