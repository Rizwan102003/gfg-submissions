class Solution:
    def findOrder(self, n, prerequisites):
        # code here 
        from collections import defaultdict
        graph = defaultdict(list)
        
        for i,j in prerequisites:
            graph[i].append(j)
        
        res = []
        visit = set()
        
        def dfs(node):
            nonlocal visit, res
            
            visit.add(node)
            for i in graph[node]:
                if i not in visit:
                    dfs(i)
            
            res.append(node)
                
            
        for i in range(n):
            if i not in visit:
                dfs(i)

        return res
