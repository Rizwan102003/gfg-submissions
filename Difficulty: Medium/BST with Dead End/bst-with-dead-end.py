class Solution:
    def isDeadEnd(self, root):
        def f(node, low, high):
            if not node: return False
            if low == high: return True
            return f(node.left, low, node.data - 1) or f(node.right, node.data + 1, high)
        return f(root, 1, 100000)