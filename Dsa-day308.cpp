#include <string>
#include <vector>

class Solution {
public:
    bool canReach(std::string s, int minJump, int maxJump) {
        int n = s.length();
        
        if (s[n - 1] == '1') {
            return false;
        }
        
        std::vector<char> dp(n, 0);
        dp[0] = 1; 
        
        int reachableCount = 0;
        
        for (int i = 1; i < n; i++) {
            if (i >= minJump) {
                if (dp[i - minJump]) {
                    reachableCount++;
                }
            }
            
            if (i > maxJump) {
                if (dp[i - maxJump - 1]) {
                    reachableCount--;
                }
            }
            
            if (s[i] == '0' && reachableCount > 0) {
                dp[i] = 1;
            }
        }
        
        return dp[n - 1];
    }
};