#User function Template for python3
class Solution:
    def findOrder(words):
        from collections import defaultdict
        from itertools import pairwise
        # Building adjacency list for topological sort
        adj = defaultdict(set)
        indegree = defaultdict(int)
        for word1, word2 in pairwise(words):
            n = min(len(word1), len(word2))
            i = 0
            while i < n and word1[i] == word2[i]:
                i += 1
            if i < n:
                c1, c2 = word1[i], word2[i]
                if c2 not in adj[c1]:
                    adj[c1].add(c2)
                    indegree[c2] += 1
            elif len(word1) > len(word2):
                return ""
        # Topological sort
        alphabet = set(c for word in words for c in word)
        q = [c for c in alphabet if indegree[c] == 0]
        order = []
        while q:
            u = q.pop()
            order.append(u)
            for v in adj[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
        if any(indegree.values()):
            # We have a cyclic dependency
            return ""
        return "".join(order)
#{ 
 # Driver Code Starts
#Initial Template for Python 3
import sys
from collections import deque

#Position this line where user code will be pasted.


def validate(original, order):
    char_map = {}
    for word in original:
        for ch in word:
            char_map[ch] = 1

    for ch in order:
        if ch not in char_map:
            return False
        del char_map[ch]

    if char_map:
        return False

    char_index = {ch: i for i, ch in enumerate(order)}

    for i in range(len(original) - 1):
        a, b = original[i], original[i + 1]
        k, n, m = 0, len(a), len(b)
        while k < n and k < m and a[k] == b[k]:
            k += 1
        if k < n and k < m and char_index[a[k]] > char_index[b[k]]:
            return False
        if k != n and k == m:
            return False

    return True


if __name__ == "__main__":
    input_data = sys.stdin.read().strip().split("\n")
    index = 0
    t = int(input_data[index])
    index += 1
    while t > 0:
        words = input_data[index].split()
        index += 1
        original = words[:]

        order = Solution.findOrder(words)

        if order == "":
            print("\"\"")
        else:
            print("true" if validate(original, order) else "false")
        print("~")
        t -= 1

# } Driver Code Ends