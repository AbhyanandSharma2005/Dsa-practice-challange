class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1'000'000'007;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        multiset<int> window;
        int left = 0;
        long long total = 1;  
        
        for (int i = 0; i < n; ++i) {
            window.insert(nums[i]);
            
            while (!window.empty() && *window.rbegin() - *window.begin() > k) {
                total = (total - dp[left] + MOD) % MOD;
                
                auto it = window.find(nums[left]);
                if (it != window.end()) {
                    window.erase(it);  
                }
                ++left;
            }
            
            dp[i + 1] = total;
            total = (total + dp[i + 1]) % MOD;
        }
        
        return dp[n];
    }
};