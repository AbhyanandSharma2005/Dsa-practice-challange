class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length, res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(nums, i, 1)) res++;
                if (simulate(nums, i, -1)) res++;
            }
        }
        return res;
    }

    private boolean simulate(int[] nums, int start, int dir) {
        int[] arr = nums.clone();
        int curr = start, n = arr.length;
        while (curr >= 0 && curr < n) {
            if (arr[curr] == 0) curr += dir;
            else {
                arr[curr]--;
                dir *= -1;
                curr += dir;
            }
        }
        for (int x : arr) if (x != 0) return false;
        return true;
    }
}
