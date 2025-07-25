import java.util.*;

class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> unique = new HashSet<>();
        int sum = 0;
        
        for (int num : nums) {
            if (num > 0) {
                unique.add(num);
            }
        }
        
        for (int val : unique) {
            sum += val;
        }

        if (sum == 0) {
            int max = nums[0];
            for (int num : nums) {
                max = Math.max(max, num);
            }
            return max;
        }

        return sum;
    }
}
