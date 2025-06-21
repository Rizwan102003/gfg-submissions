from collections import deque
class Solution:
    def catchThieves(self, arr, k):
        #code  here
        police = deque([i for i,person in enumerate(arr) if person=='P'])
        theives = deque([i for i,person in enumerate(arr) if person=='T'])
        count = 0
        while len(police) and len(theives):
            if abs(theives[0]-police[0]) <= k:
                count += 1
                theives.popleft()
                police.popleft()
            elif theives[0] < police[0]:
                theives.popleft()
            else:
                police.popleft()
        return count