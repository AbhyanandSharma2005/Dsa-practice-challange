class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
            
            currentLevel++;
        }
        
        return maxLevel;
    }
};