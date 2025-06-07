class Solution:
    def longestCommonSum(self, a1, a2):
        #Code here.
        n = len(a1)
        d = {0: -1}
        s = 0
        maxi = 0
        for i in range(n):
            s += a1[i] - a2[i]
            t = s - 0
            if t not in d:
                d[t] = i
            else:
                maxi = max(maxi, i-d[t])
        return maxi