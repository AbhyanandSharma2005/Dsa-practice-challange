static constexpr long long mod = 1e9 + 7;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        std::vector<std::vector<std::array<long long, 2>>> dp(zero + 1, std::vector<std::array<long long, 2>>(one + 1, std::array<long long, 2>{}));
        size_t bound = std::min(zero, limit);
        for (size_t i = 0; i <= bound; ++i) dp[i][0][0] = 1;
        bound = std::min(one, limit);
        for (size_t j = 0; j <= bound; ++j) dp[0][j][1] = 1;
        for (size_t i = 1; i <= zero; ++i) {
            for (size_t j = 1; j <= one; ++j) {
                if (i > limit) {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
                } else dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                if (j > limit) {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
                } else dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};