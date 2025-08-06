class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        class Tree:
            def __init__(self, val = None):
                self.val = val
                self.left = None
                self.right = None

        def visitor(node):
            return node.left.val if node.left.val >= node.right.val else node.right.val

        def segment_tree(baskets):
            def dfs(root, start, end):
                mid = (start + end) // 2
                if start < mid:
                    root.left = Tree(0)
                    dfs(root.left, start, mid)
                    root.left.val = visitor(root.left)
                else:
                    root.left = Tree(baskets[start])
                if mid + 1 < end:
                    root.right = Tree(0)
                    dfs(root.right, mid + 1, end)
                    root.right.val = visitor(root.right)
                else:
                    root.right = Tree(baskets[end])
            root = Tree(0)
            dfs(root, 0, len(baskets) - 1)
            root.val = visitor(root)
            return root

        def is_placed(root, fruit):
            if fruit > root.val:
                return False
            if root.left and fruit <= root.left.val:
                is_placed(root.left, fruit)
            elif root.right:
                is_placed(root.right, fruit)
            if not root.left and not root.right:
                root.val = 0
            else:
                root.val = visitor(root)
            return True

        unplaced = len(fruits)
        root = segment_tree(baskets)
        for fruit in fruits:
            if is_placed(root, fruit):
                unplaced -= 1
        return unplaced