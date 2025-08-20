class Solution:
    def searchMatrix(self, mat, x):
        # code here
        for lst in mat:
            if x in lst:
                return True
                
        return False