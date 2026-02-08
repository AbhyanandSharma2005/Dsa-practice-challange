/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfsHeight(TreeNode *node)
    {
        if(node == nullptr)
            return 0;
        int lftHt = dfsHeight(node->left);
        if(lftHt == -1)
            return -1;
        int rgtHt = dfsHeight(node->right);
        if(rgtHt == -1)
            return -1;
        if(abs(lftHt-rgtHt) > 1)
            return -1;
        return 1 + max(lftHt, rgtHt);
    }
 public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};