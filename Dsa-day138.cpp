class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1000000007;
        unordered_map<int, long long> cnt;
        for (auto& p : points) ++cnt[p[1]];

        long long sum = 0, sum_sq = 0;
        for (auto& [y, f] : cnt) {
            if (f >= 2) {
                long long c = f * (f - 1) / 2;
                sum = (sum + c) % MOD;
                sum_sq = (sum_sq + c * c % MOD) % MOD;
            }
        }
        long long total = sum * sum % MOD;
        long long ans = (total - sum_sq + MOD) % MOD;
        ans = ans * 500000004LL % MOD;  // divide by 2
        return ans;
    }
};