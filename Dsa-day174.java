class Solution {
    private long maxProduct = 0;
    private long totalSum = 0;
    private static final int MOD = 1000000007;
    
    public int maxProduct(TreeNode root) {
        totalSum = calculateSum(root);
        findMaxProduct(root);
        return (int)(maxProduct % MOD);
    }
    
    private long calculateSum(TreeNode node) {
        if (node == null) return 0;
        return node.val + calculateSum(node.left) + calculateSum(node.right);
    }
    
    private long findMaxProduct(TreeNode node) {
        if (node == null) return 0;
        
        long leftSum = findMaxProduct(node.left);
        long rightSum = findMaxProduct(node.right);
        long currentSum = node.val + leftSum + rightSum;
        
        long product = currentSum * (totalSum - currentSum);
        maxProduct = Math.max(maxProduct, product);
        
        return currentSum;
    }
}