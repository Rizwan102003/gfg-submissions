class Solution:
    def isInterleave(self, s1, s2, s3):
        # code here
        from functools import cache
        m, n, o = len(s1), len(s2), len(s3)
        if m + n != o:
            return False
        
        @cache
        def dfs(i=0, j=0, k=0):
            if i == m and j == n and k == o:
                return True
            if i < m and s1[i] == s3[k] and dfs(i + 1, j, k + 1):
                return True
            if j < n and s2[j] == s3[k] and dfs(i, j + 1, k + 1):
                return True
            return False
        
        return dfs()