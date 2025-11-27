class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long ans = LLONG_MIN;
        vector<long long> mod_min(k, LLONG_MAX / 2);
        
        for (int i = 0; i <= n; ++i) {
            int r = i % k;
            if (mod_min[r] != LLONG_MAX / 2) {
                ans = max(ans, prefix[i] - mod_min[r]);
            }
            mod_min[r] = min(mod_min[r], prefix[i]);
        }
        
        return ans;
    }
};