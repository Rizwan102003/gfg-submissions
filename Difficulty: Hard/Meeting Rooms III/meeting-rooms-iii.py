#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq


# } Driver Code Ends

#User function Template for python3
class Solution:
    def mostBooked(self, n, meetings):
        #code here
        from heapq import heappush, heappop
        from collections import Counter
        
        rooms = list(range(n))
        used = []
        counter = Counter()
        
        for start, end in sorted(meetings):
            while used and used[0][0] <= start:
                _, r = heappop(used)
                heappush(rooms, r)
            if rooms:
                r = heappop(rooms)
                heappush(used, (end, r))
            else:
                t, r = heappop(used)
                heappush(used, (t-start+end, r))
                
            counter[r] += 1
        return counter.most_common(1).pop()[0]


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    import sys
    input = sys.stdin.read().split()
    it = iter(input)
    t = int(next(it))
    while t > 0:
        t -= 1
        n = int(next(it))
        m = int(next(it))
        meetings = []
        for _ in range(m):
            s = int(next(it))
            e = int(next(it))
            meetings.append([s, e])
        sol = Solution()
        res = sol.mostBooked(n, meetings)
        print(res)
        print("~")
# } Driver Code Ends