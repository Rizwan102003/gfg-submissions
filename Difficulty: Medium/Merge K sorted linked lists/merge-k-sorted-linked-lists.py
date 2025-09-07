'''
class Node:
    def _init_(self, x):
        self.data = x
        self.next = None
'''

class Solution:
    def mergeKLists(self, arr):
        # code here
        import heapq
        hp=[(nd.data,ix,) for ix,nd in enumerate(arr)]
        heapq.heapify(hp)
        dum=Node(-1)
        cur=dum
        while hp:
            _,ix=heapq.heappop(hp)
            cur.next=arr[ix]
            cur=cur.next
            arr[ix]=arr[ix].next
            if arr[ix]:
                heapq.heappush(hp,(arr[ix].data,ix,))
        return dum.next