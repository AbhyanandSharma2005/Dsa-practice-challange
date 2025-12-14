class Solution {
    public int numberOfWays(String corridor) {
        final int MOD = 1000000007;
        int ptr = 0;
        
        ptr = corridor.indexOf('S', ptr);
        if (ptr == -1) return 0;
        
        ptr = corridor.indexOf('S', ptr + 1);
        if (ptr == -1) return 0;
        
        long ans = 1;
        
        while (true) {
            int next = corridor.indexOf('S', ptr + 1);
            if (next == -1) break;
            
            ans = ans * (next - ptr) % MOD;
            
            ptr = corridor.indexOf('S', next + 1);
            if (ptr == -1) return 0;
        }
        
        return (int) ans;
    }
}