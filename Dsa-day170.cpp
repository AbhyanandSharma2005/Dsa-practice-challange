class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        // Initial state: 6 patterns each for Type A and Type B
        long long dpA = 6;  // ABA patterns
        long long dpB = 6;  // ABC patterns
        
        // Build up row by row
        for (int i = 2; i <= n; i++) {
            long long newDpA = (3LL * dpA + 2LL * dpB) % MOD;
            long long newDpB = (2LL * dpA + 2LL * dpB) % MOD;
            
            dpA = newDpA;
            dpB = newDpB;
        }
        
        return static_cast<int>((dpA + dpB) % MOD);
    }
};