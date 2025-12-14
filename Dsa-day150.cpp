class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1000000007;
        size_t ptr = 0;
        
        ptr = corridor.find('S', ptr);
        if (ptr == string::npos) return 0;
        
        ptr = corridor.find('S', ptr + 1);
        if (ptr == string::npos) return 0;
        
        long long ans = 1;
        
        while (true) {
            size_t next = corridor.find('S', ptr + 1);
            if (next == string::npos) break;
            
            ans = ans * (next - ptr) % MOD;
            
            ptr = corridor.find('S', next + 1);
            if (ptr == string::npos) return 0;
        }
        
        return ans;
    }
};