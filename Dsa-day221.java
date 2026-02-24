class Solution {
    public int sumRootToLeaf(TreeNode root) {
        return solve(root, 0);
    }

    private int solve(TreeNode root, int value){

        if(root == null){
            return 0;
        }

        value = (2 * value) + root.val;

        if(root.left == null && root.right == null){
            return value;
        }

        return solve(root.left, value) + solve(root.right, value);
    }
}