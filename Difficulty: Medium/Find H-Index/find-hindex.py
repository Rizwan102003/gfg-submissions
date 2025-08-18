class Solution:
    def hIndex(self, citations):
        #code here
        import heapq
        heapq.heapify(citations)
        h=len(citations)
        while citations:
            if citations[0]>=h:
                return h
            heapq.heappop(citations)
            h-=1
        return 0

