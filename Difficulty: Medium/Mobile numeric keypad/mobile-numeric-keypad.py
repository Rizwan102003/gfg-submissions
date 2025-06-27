class Solution:
	def getCount(self, n):
		# code here
		adj={}
        adj[0]=set([0,8])
        adj[1]=set([1,2,4])
        adj[2]=set([1,2,3,5])
        adj[3]=set([2,3,6])
        adj[4]=set([1,4,5,7])
        adj[5]=set([2,4,5,6,8])
        adj[6]=set([3,5,6,9])
        adj[7]=set([4,7,8])
        adj[8]=set([5,7,8,9,0])
        adj[9]=set([6,8,9])
        from functools import lru_cache
        @lru_cache(None)
        def dfs(p,n=n):
            nonlocal adj
            if n==1:
                return 1
            ret=0
            for nxt in adj[p]:
                ret+=dfs(nxt,n-1)
            return ret
        ret=0
        for sta in range(0,10):
            ret+=dfs(sta)
        return ret