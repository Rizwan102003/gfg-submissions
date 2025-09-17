class Solution:
    def decodedString(self, s):
        # code here
        tokens = list(s)
        
        def parse(tokens):
            ret = []
            while tokens:
                #cur = tokens.pop(0)
                match cur := tokens.pop(0):
                    case c if c.isalpha():
                        ret.append(c)
                    case c if c.isdigit():
                        n = int(c)
                        while tokens and tokens[0].isdigit():
                            n = n*10 + int(tokens.pop(0))
                        ret.extend(parse(tokens)*n)
                    case '[':
                        continue
                    case ']':
                        return ret
            return ret
        
        return "".join(parse(tokens))