import java.util.Arrays;

class Solution {
    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        int[] arr = Arrays.copyOf(nums, n);
        int ans = 0;

        while (!isNonDecreasing(arr, n)) {
            ans++;
            int minSum = Integer.MAX_VALUE;
            int pos = -1;
            for (int i = 1; i < n; i++) {
                int currentSum = arr[i - 1] + arr[i];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    pos = i;
                }
            }
            arr[pos - 1] = minSum;
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }

        return ans;
    }

    private boolean isNonDecreasing(int[] arr, int length) {
        for (int i = 1; i < length; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
}