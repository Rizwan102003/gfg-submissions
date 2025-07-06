class Solution:
    def topKSumPairs(self, a, b, k):
        # code here
        n=len(a)
        a.sort(reverse=True)
        b.sort(reverse=True)
        pq=[]
        heapq.heappush(pq,(-a[0]-b[0],0,0))
        visited={(0,0)}
        ans=[]
        for _ in range(k):
            curr,i,j=heapq.heappop(pq)
            ans.append(-curr)
            if i+1<n and (i+1,j) not in visited:
                heapq.heappush(pq,(-a[i+1]-b[j],i+1,j))
                visited.add((i+1,j))
            if j+1<n and (i,j+1) not in visited:
                heapq.heappush(pq,(-a[i]-b[j+1],i,j+1))
                visited.add((i,j+1))
        return ans