class Solution:
	def minJumps(self, arr):
	    # code here
	    jump, des, pos = 0, 0, 0
        for i in range(len(arr)-1):
            des = max(des, i + arr[i])
            if(i >= des):
                return -1
            if(pos == i):
                pos = des
                jump += 1
        return jump