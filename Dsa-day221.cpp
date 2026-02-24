class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int value){
        if(!node) return 0;

        value = value * 2 + node->val;

        if(!node->left && !node->right)
            return value;

        return dfs(node->left, value) + dfs(node->right, value);
    }
};