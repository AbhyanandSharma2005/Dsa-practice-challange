class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        long prev = Long.MIN_VALUE;
        int count = 0;
        for (int x : nums) {
            long low = (long)x - k, high = (long)x + k;
            long val = Math.max(prev + 1, low);
            if (val <= high) {
                count++;
                prev = val;
            }
        }
        return count;
    }
}
