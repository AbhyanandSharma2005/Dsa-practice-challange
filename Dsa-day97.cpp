class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            int lo = lower_bound(nums.begin(), nums.begin() + i, nums[i] - k) - nums.begin();
            int hi = upper_bound(nums.begin() + j, nums.end(), nums[i] + k) - nums.begin();
            ans = max(ans, min((hi - j) + (i - lo), numOperations) + j - i);
            i = j;
        }
        int l = 0, r = 0;
        while (l < n) {
            if (r < n && nums[r] - nums[l] <= 2 * k) {
                r++;
                ans = max(ans, min(r - l, numOperations));
            } else l++;
        }
        return ans;
    }
};
