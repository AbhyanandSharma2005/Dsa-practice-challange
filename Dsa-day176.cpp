class Solution {
public:
    TreeNode* result;
    int maxDepth;
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = -1;
        result = nullptr;
        dfs(root, 0);
        return result;
    }
    
private:
    int dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth - 1;
        }
        
        int leftDepth = dfs(node->left, depth + 1);
        int rightDepth = dfs(node->right, depth + 1);
        
        if (leftDepth > maxDepth || rightDepth > maxDepth) {
            maxDepth = max(leftDepth, rightDepth);
        }
        
        if (leftDepth == maxDepth && rightDepth == maxDepth) {
            result = node;
        }
        
        return max(leftDepth, rightDepth);
    }
};