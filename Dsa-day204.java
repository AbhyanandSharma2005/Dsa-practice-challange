class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int maxKeep = 1;
        int right = 0;
        
        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= (long)nums[left] * k) {
                right++;
            }
            maxKeep = Math.max(maxKeep, right - left);
        }
        
        return n - maxKeep;
    }
}