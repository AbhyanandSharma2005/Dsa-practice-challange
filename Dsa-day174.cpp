class Solution {
private:
    long long maxProd = 0;
    long long totalSum = 0;
    const int MOD = 1000000007;
    
    long long calculateSum(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->val + calculateSum(node->left) + calculateSum(node->right);
    }
    
    long long findMaxProduct(TreeNode* node) {
        if (node == nullptr) return 0;
        
        long long leftSum = findMaxProduct(node->left);
        long long rightSum = findMaxProduct(node->right);
        long long currentSum = node->val + leftSum + rightSum;
        
        long long product = currentSum * (totalSum - currentSum);
        maxProd = max(maxProd, product);
        
        return currentSum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        totalSum = calculateSum(root);
        findMaxProduct(root);
        return maxProd % MOD;
    }
};