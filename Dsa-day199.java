class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int minCost = Integer.MAX_VALUE;
        
        // First cut after index i (0-based)
        // Second cut after index j
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = nums[0] + nums[i] + nums[j];
                minCost = Math.min(minCost, cost);
            }
        }
        
        return minCost;
    }
}