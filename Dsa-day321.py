# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        root = None
        mapped = {}
        parent = {}
        for item in descriptions:
            node = mapped.get(item[0])
            if node is None:
                node = TreeNode(item[0])
                mapped[item[0]] = node
            if root is None:
                root = node
            child = mapped.get(item[1])
            if child is not None:
                if child == root:
                    pNode = node
                    rNode = node
                    while True:
                        pNode = parent.get(pNode)
                        if pNode is None:
                            break
                        rNode = pNode
                    root = rNode
            else:
                child = TreeNode(item[1])
                mapped[item[1]] = child
            if item[2] == 1:
                node.left = child
            else:
                node.right = child
            parent[child] = node
        return root