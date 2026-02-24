class Solution:
    def sumRootToLeaf(self, root):
        def dfs(node, value):
            if not node:
                return 0

            value = value * 2 + node.val

            if not node.left and not node.right:
                return value

            return dfs(node.left, value) + dfs(node.right, value)

        return dfs(root, 0)