"""
Definition for singly Link List Node
class Node:
    def __init__(self,x):
        self.val=x
        self.next=None

"""
class Solution:
    def primeList(self, head):
        def nearestPrime(n):
            if self.isPrime(n):
                return n
            offset = 1
            while True:
                if self.isPrime(n - offset):
                    return n - offset
                if self.isPrime(n + offset):
                    return n + offset
                offset += 1
        curr = head
        while curr:
            curr.val = nearestPrime(curr.val)
            curr = curr.next
        return head

    def isPrime(self, n):
        if n <= 1:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        for i in range(3, int(n**0.5) + 1, 2):
            if n % i == 0:
                return False
        return True
#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.val = x
        self.next = None


def printList(node):
    while (node != None):
        print(node.val, end=" ")
        node = node.next
    print()


def inputList():

    val = [int(i) for i in input().strip().split()
           ]  #all data of linked list in a line
    head = Node(val[0])
    tail = head
    for i in range(1, len(val)):
        tail.next = Node(val[i])
        tail = tail.next
    return head


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        head = inputList()

        obj = Solution()
        res = obj.primeList(head)

        printList(res)

        print("~")

# } Driver Code Ends