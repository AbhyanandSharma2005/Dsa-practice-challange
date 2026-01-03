class Solution {
    public int numOfWays(int n) {
        final int MOD = 1_000_000_007;
        
        // Initial state: 6 patterns each for Type A and Type B
        long dpA = 6;  // ABA patterns
        long dpB = 6;  // ABC patterns
        
        // Build up row by row
        for (int i = 2; i <= n; i++) {
            long newDpA = (3 * dpA + 2 * dpB) % MOD;
            long newDpB = (2 * dpA + 2 * dpB) % MOD;
            
            dpA = newDpA;
            dpB = newDpB;
        }
        
        return (int)((dpA + dpB) % MOD);
    }
}