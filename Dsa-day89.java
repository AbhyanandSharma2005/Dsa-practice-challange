class Solution {
    private boolean isStrictlyIncreasing(List<Integer> nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums.get(i) >= nums.get(i+1)) {
                return false;
            }
        }
        return true;
    }

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        if (n < 2 * k) {
            return false;
        }
        
        for (int a = 0; a <= n - 2 * k; a++) {
            // Check the first subarray: nums[a...a + k - 1]
            if (isStrictlyIncreasing(nums, a, k)) {
                // Check the second adjacent subarray: nums[a + k...a + 2 * k - 1]
                if (isStrictlyIncreasing(nums, a + k, k)) {
                    return true;
                }
            }
        }
        
        return false;
    }
}