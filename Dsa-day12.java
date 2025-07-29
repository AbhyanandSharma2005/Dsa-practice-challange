class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int[] last = new int[32]; 

        for (int i = 0; i < 32; i++) {
            last[i] = -1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (((nums[i] >> b) & 1) == 1) {
                    last[b] = i;
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; b++) {
                if (last[b] != -1) {
                    maxReach = Math.max(maxReach, last[b]);
                }
            }

            res[i] = maxReach - i + 1;
        }

        return res;
    }
}
