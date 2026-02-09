class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes = []
        
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            nodes.append(node)
            inorder(node.right)
        
        def build(left, right):
            if left > right:
                return None
            
            mid = (left + right) // 2
            node = nodes[mid]
            node.left = build(left, mid - 1)
            node.right = build(mid + 1, right)
            return node
        
        inorder(root)
        return build(0, len(nodes) - 1)