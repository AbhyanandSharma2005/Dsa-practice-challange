class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        long total = 0;
        for (int x : nums) total += x;
        int rem = (int)(total % p);
        if (rem == 0) return 0;
        
        Map<Integer, Integer> last = new HashMap<>();
        last.put(0, -1);
        
        long pref = 0;
        int ans = n;
        
        for (int i = 0; i < n; ++i) {
            pref += nums[i];
            int curr = (int)(pref % p);
            int target = (curr - rem + p) % p;
            if (last.containsKey(target)) {
                ans = Math.min(ans, i - last.get(target));
            }
            last.put(curr, i);
        }
        return ans < n ? ans : -1;
    }
}