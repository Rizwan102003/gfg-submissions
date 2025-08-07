class Solution:
    def minDifference(self, arr):
        # code here
        second = []
        for t in arr:
            h,m,s = map(int,t.split(':'))
            total = h * 3600 + m * 60 + s
            second.append(total)


        second.sort()  
        min_diff = 86400
            
        for i in range(len(second)):
            current = second[i]
            nexttime = second[(i+1) % len(second)]
            diff = (nexttime - current) % 86400
            min_diff = min(min_diff,diff)
        return min_diff
        
