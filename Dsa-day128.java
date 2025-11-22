class Solution {
    public int minimumOperations(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            int r = x % 3;
            ans += Math.min(r, 3 - r);
        }
        return ans;
    }
}