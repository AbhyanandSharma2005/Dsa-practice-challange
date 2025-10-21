class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxNum = 0;
        for (int num : nums) maxNum = Math.max(maxNum, num);
        int[] counts = new int[maxNum + k + 1];
        for (int num : nums) counts[num]++;
        int[] pre = new int[counts.length];
        pre[0] = counts[0];
        for (int i = 1; i < counts.length; ++i)
            pre[i] = pre[i - 1] + counts[i];
        int res = 0;
        for (int i = 0; i + k < counts.length; ++i) {
            int left = Math.max(0, i - k - 1);
            int right = Math.min(i + k, pre.length - 1);
            int mid = counts[i];
            int candidate = pre[right] - pre[left] - mid;
            res = Math.max(res, mid + Math.min(numOperations, candidate));
        }
        return res;
    }
}
