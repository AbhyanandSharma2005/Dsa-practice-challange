class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        // i = end of first subarray
        // j = end of second subarray
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = nums[0] + nums[i] + nums[j];
                if (cost < ans) {
                    ans = cost;
                }
            }
        }
        
        return ans;
    }
};