class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> pref(n + 1, 0);          
        vector<long long> stratpref(n + 1, 0);     
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + prices[i];
            stratpref[i + 1] = stratpref[i] + (long long)strategy[i] * prices[i];
        }
        
        long long best = stratpref[n];  
        
        int half = k / 2;
        for (int i = 0; i <= n - k; i++) {
            long long seg = pref[i + k] - pref[i + half];
            
            long long rest = stratpref[i] + (stratpref[n] - stratpref[i + k]);
            
            best = max(best, seg + rest);
        }
        
        return best;
    }
};