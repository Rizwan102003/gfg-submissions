class Solution:
    def maxSum(self, arr):
        # code here
        return max(arr[i-1]+arr[i] for i in range(1,len(arr)))
    
