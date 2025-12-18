class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.length;
        long[] pref = new long[n + 1];           
        long[] stratpref = new long[n + 1];      
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + prices[i];
            stratpref[i + 1] = stratpref[i] + (long)strategy[i] * prices[i];
        }
        
        long best = stratpref[n];          
        int half = k / 2;
        for (int i = 0; i <= n - k; i++) {
            long seg = pref[i + k] - pref[i + half];
            
            long rest = stratpref[i] + (stratpref[n] - stratpref[i + k]);
            
            best = Math.max(best, seg + rest);
        }
        
        return best;
    }
}