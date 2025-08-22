class Solution:
    def median(self, mat):
    	# code here 
    	l=[]
        for i in mat:
            for j in i:
                l.append(j)
        l.sort()
        return l[len(l)//2]