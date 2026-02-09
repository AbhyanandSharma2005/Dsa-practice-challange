class Solution {
    private:
    void helper(TreeNode* root,vector<int>&temp){
        if(root == NULL)
        return;

        helper(root->left,temp);
        temp.push_back(root->val);
        helper(root->right,temp);
    }
    TreeNode* build(int s,int e,vector<int>&temp){
        if(s>e)
        return NULL;

        int mid=s+(e-s)/2;

        TreeNode* root=new TreeNode(temp[mid]);
        root->left=build(s,mid-1,temp);
        root->right=build(mid+1,e,temp);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        helper(root,temp);

        root=build(0,temp.size()-1,temp);
        return root;
    }
};