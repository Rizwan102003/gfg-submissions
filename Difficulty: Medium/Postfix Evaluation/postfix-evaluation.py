class Solution:
    import operator
    
    OP_TO_FUNC = {
        "+": operator.add,
        "-": operator.sub,
        "*": operator.mul,
        "/": operator.floordiv,
        "^": operator.pow,
    }
    
    def evaluatePostfix(self, stack):
        if func := self.OP_TO_FUNC.get(stack[-1]):
            stack.pop()  # pop the operation character
            right = self.evaluatePostfix(stack)
            left = self.evaluatePostfix(stack)
            return func(left, right)
        else:
            return int(stack.pop())