class Solution:
    def minCost(self, heights, cost):
        pairs=sorted(zip(heights,cost))
        total_weight=sum(cost)
        acc=0
        for h,c in pairs:
            acc+=c
            if acc>=total_weight/2:
                target=h
                break
        return sum(abs(h-target)*c for h,c in pairs)