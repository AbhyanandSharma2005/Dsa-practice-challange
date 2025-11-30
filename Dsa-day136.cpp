class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        int rem = total % p;
        if (rem == 0) return 0;
        
        unordered_map<int, int> last;
        last[0] = -1;
        
        long long pref = 0;
        int ans = n;
        
        for (int i = 0; i < n; ++i) {
            pref += nums[i];
            int curr = pref % p;
            int target = (curr - rem + p) % p;
            if (last.count(target)) {
                ans = min(ans, i - last[target]);
            }
            last[curr] = i;
        }
        return ans < n ? ans : -1;
    }
};