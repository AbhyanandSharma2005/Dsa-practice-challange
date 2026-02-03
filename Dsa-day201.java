class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        
        for (int p = 1; p < n - 2; p++) {
            for (int q = p + 1; q < n - 1; q++) {
                boolean valid = true;
                
                for (int i = 0; i < p; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    for (int i = p; i < q; i++) {
                        if (nums[i] <= nums[i + 1]) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    for (int i = q; i < n - 1; i++) {
                        if (nums[i] >= nums[i + 1]) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    return true;
                }
            }
        }
        
        return false;
    }
}