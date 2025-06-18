class Solution:
    def palinParts (self, s):
        # code here
        def isPallindrom(s,l,r):
            while l<r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True
        n = len(s)
        res = []
        def helper(i,curr):
            if i == n : 
                res.append(curr[:])
                return
            for j in range(i,n):
                if isPallindrom(s,i,j):
                    curr.append(s[i:j+1])
                    helper(j+1,curr)
                    curr.pop()
        helper(0,[])
        return res

