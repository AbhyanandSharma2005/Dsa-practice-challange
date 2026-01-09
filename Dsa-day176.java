class Solution {
    private TreeNode result;
    private int maxDepth;
    
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        maxDepth = -1;
        result = null;
        dfs(root, 0);
        return result;
    }
    
    private int dfs(TreeNode node, int depth) {
        if (node == null) {
            return depth - 1;
        }
        
        int leftDepth = dfs(node.left, depth + 1);
        int rightDepth = dfs(node.right, depth + 1);
        
        if (leftDepth > maxDepth || rightDepth > maxDepth) {
            maxDepth = Math.max(leftDepth, rightDepth);
        }
        
        if (leftDepth == maxDepth && rightDepth == maxDepth) {
            result = node;
        }
        
        return Math.max(leftDepth, rightDepth);
    }
}