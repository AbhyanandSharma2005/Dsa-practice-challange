#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        vector<vector<vector<long long>>> memo(n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));
        
        function<long long(int, int, int)> dfs = [&](int i, int rem, int state) -> long long {
            if (i == n) {
                return (state == 0) ? 0LL : LLONG_MIN / 2;
            }
            
            if (memo[i][rem][state] != -1) {
                return memo[i][rem][state];
            }
            
            long long& ans = memo[i][rem][state];
            
            if (state == 0) {
                ans = dfs(i + 1, rem, 0);
                
                if (rem > 0) {
                    ans = max(ans, dfs(i + 1, rem - 1, 1) - prices[i]);
                    ans = max(ans, dfs(i + 1, rem - 1, 2) + prices[i]);
                }
            }
            else if (state == 1) {
                long long keep = dfs(i + 1, rem, 1);
                long long sell = dfs(i + 1, rem, 0) + prices[i];
                ans = max(keep, sell);
            }
            else if (state == 2) {
                long long keep = dfs(i + 1, rem, 2);
                long long cover = dfs(i + 1, rem, 0) - prices[i];
                ans = max(keep, cover);
            }
            
            return ans;
        };
        
        long long result = dfs(0, k, 0);
        return result;
    }
};