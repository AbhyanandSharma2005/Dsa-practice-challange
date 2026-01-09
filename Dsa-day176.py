class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.result = None
        self.max_depth = -1
        
        def dfs(node, depth):
            if not node:
                return depth - 1
            
            left_depth = dfs(node.left, depth + 1)
            right_depth = dfs(node.right, depth + 1)
            
            if left_depth > self.max_depth or right_depth > self.max_depth:
                self.max_depth = max(left_depth, right_depth)
            
            if left_depth == self.max_depth and right_depth == self.max_depth:
                self.result = node
            
            return max(left_depth, right_depth)
        
        dfs(root, 0)
        return self.result