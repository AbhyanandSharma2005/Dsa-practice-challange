import java.util.*;

class Solution {
    public long minimumDifference(int[] nums) {
        int n = nums.length / 3;
        int len = nums.length;

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        long leftSum = 0;
        long[] leftMins = new long[len];

        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            maxHeap.offer(nums[i]);
        }
        leftMins[n - 1] = leftSum;

        for (int i = n; i < 2 * n; i++) {
            leftSum += nums[i];
            maxHeap.offer(nums[i]);
            leftSum -= maxHeap.poll();
            leftMins[i] = leftSum;
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long rightSum = 0;
        long[] rightMaxs = new long[len];

        for (int i = len - 1; i >= len - n; i--) {
            rightSum += nums[i];
            minHeap.offer(nums[i]);
        }
        rightMaxs[len - n] = rightSum;

        for (int i = len - n - 1; i >= n; i--) {
            rightSum += nums[i];
            minHeap.offer(nums[i]);
            rightSum -= minHeap.poll();
            rightMaxs[i] = rightSum;
        }

        long res = Long.MAX_VALUE;
        for (int i = n - 1; i < 2 * n; i++) {
            res = Math.min(res, leftMins[i] - rightMaxs[i + 1]);
        }

        return res;
    }
}
