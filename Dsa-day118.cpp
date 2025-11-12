class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ones = count(nums.begin(), nums.end(), 1);
        if (ones) return n - ones;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
