'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def kthSmallest(self, root, k): 
        # code here
        ret=-1
        def dfs(cur=root):
            nonlocal k,ret
            if not cur:
                return
            dfs(cur.left)
            k-=1
            if k==0:
                ret=cur.data
                return
            dfs(cur.right)
        dfs()
        return ret