class Solution:
    def farMin(self, arr):
        # Code Here
        n = len(arr)
        ans = [-1] * n
        v = [(arr[i], i) for i in range(n)]
        v.sort(key=lambda x: x[0])
        maxi = v[0][1]
        for i in range(1, n):
            if maxi > v[i][1]:
                ans[v[i][1]] = maxi
            maxi = max(maxi, v[i][1])

        return ans