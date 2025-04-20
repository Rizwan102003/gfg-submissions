#User function Template for python3
class Solution:
    def findDuplicate(self, arr):
        n=len(arr)+1
        for i in range(len(arr)):
            x=arr[i]%n-1
            if arr[x]>=n:
                return x+1
            arr[x]+=n
        return -1
#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        print(ob.findDuplicate(arr))
        print("~")

# } Driver Code Ends