class Solution {
    public int missingMultiple(int[] nums, int k) {
        boolean[] present = new boolean[101];
        for (int num : nums) {
            present[num] = true;
        }
        int target = k;
        while (target <= 100 && present[target]) {
            target += k;
        }
        return target;
    }
}