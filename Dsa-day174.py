class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.maxProduct = 0
        self.totalSum = 0
        MOD = 10**9 + 7
        
        def calculateSum(node):
            if not node:
                return 0
            return node.val + calculateSum(node.left) + calculateSum(node.right)
        
        def findMaxProduct(node):
            if not node:
                return 0
            
            leftSum = findMaxProduct(node.left)
            rightSum = findMaxProduct(node.right)
            currentSum = node.val + leftSum + rightSum
            
            product = currentSum * (self.totalSum - currentSum)
            self.maxProduct = max(self.maxProduct, product)
            
            return currentSum
        
        self.totalSum = calculateSum(root)
        findMaxProduct(root)
        return self.maxProduct % MOD