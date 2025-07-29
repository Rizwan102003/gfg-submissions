class Solution:
    def asciirange(self, s):
        # code here
        result = []
        n = len(s)
        
        for ch in set(s):
            first = s.find(ch)
            last = s.rfind(ch)
            
            if first != last:
                sum_ascii = 0
                for i in range(first + 1, last):
                    sum_ascii += ord(s[i])
                if sum_ascii > 0:
                    result.append(sum_ascii)
        
        return result