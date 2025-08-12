#include <vector>
#include <cmath>

class Solution {
public:
    int numberOfWays(int n, int x) {
        int MOD = 1e9 + 7;

        std::vector<int> dp(n + 1, 0);
        
        dp[0] = 1;

        int num = 1;
        while (true) {
            int p = static_cast<int>(pow(num, x));

            if (p > n) {
                break;
            }

            for (int j = n; j >= p; j--) {
                dp[j] = (dp[j] + dp[j - p]) % MOD;
            }
            
            num++;
        }

        return dp[n];
    }
};