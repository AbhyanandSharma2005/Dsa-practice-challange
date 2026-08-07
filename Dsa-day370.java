import java.util.Arrays;

class Solution {
    public String smallestNumber(String num, long t) {
        long temp = t;
        int r2 = 0, r3 = 0, r5 = 0, r7 = 0;
        
        while (temp % 2 == 0) { r2++; temp /= 2; }
        while (temp % 3 == 0) { r3++; temp /= 3; }
        while (temp % 5 == 0) { r5++; temp /= 5; }
        while (temp % 7 == 0) { r7++; temp /= 7; }
        
        // If t has prime factors other than 2, 3, 5, or 7, it's impossible.
        if (temp > 1) {
            return "-1";
        }
        
        int n = num.length();
        int[] f2 = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int[] f3 = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int[] f5 = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int[] f7 = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
        
        int[] pref2 = new int[n + 1];
        int[] pref3 = new int[n + 1];
        int[] pref5 = new int[n + 1];
        int[] pref7 = new int[n + 1];
        
        boolean hasZero = false;
        int first_zero = -1;
        
        for (int i = 0; i < n; i++) {
            int d = num.charAt(i) - '0';
            if (d == 0) {
                hasZero = true;
                if (first_zero == -1) first_zero = i;
            }
            pref2[i + 1] = pref2[i] + f2[d];
            pref3[i + 1] = pref3[i] + f3[d];
            pref5[i + 1] = pref5[i] + f5[d];
            pref7[i + 1] = pref7[i] + f7[d];
        }
        
        // Already zero-free and completely divisible -> No increment required
        if (!hasZero && pref2[n] >= r2 && pref3[n] >= r3 && pref5[n] >= r5 && pref7[n] >= r7) {
            return num;
        }
        
        int max_r2 = 50;
        int max_r3 = 30; // Fits since max factors under bounds: 2^46 < 10^14 and 3^29 < 10^14
        String[][] dp = new String[max_r2 + 1][max_r3 + 1];
        
        String inf = "9".repeat(100);
        for (int i = 0; i <= max_r2; i++) {
            Arrays.fill(dp[i], inf);
        }
        dp[0][0] = "";
        char[] digits_to_try = {'2', '3', '4', '6', '8', '9'};
        
        for (int i = 0; i <= max_r2; i++) {
            for (int j = 0; j <= max_r3; j++) {
                if (i == 0 && j == 0) continue;
                String best = inf;
                for (char d : digits_to_try) {
                    int d_val = d - '0';
                    int ni = Math.max(0, i - f2[d_val]);
                    int nj = Math.max(0, j - f3[d_val]);
                    
                    if (dp[ni][nj].length() < 100) {
                        char[] candArr = (dp[ni][nj] + d).toCharArray();
                        Arrays.sort(candArr);
                        String cand = new String(candArr);
                        if (cand.length() < best.length() || (cand.length() == best.length() && cand.compareTo(best) < 0)) {
                            best = cand;
                        }
                    }
                }
                dp[i][j] = best;
            }
        }
        
        int start_i = (first_zero == -1) ? n - 1 : first_zero;
        
        // Try modifying bounded from the back to maintain the maximum possible prefix
        for (int i = start_i; i >= 0; i--) {
            int orig_d = num.charAt(i) - '0';
            int start_d = orig_d + 1;
            
            for (int d = start_d; d <= 9; d++) {
                int rem2 = Math.max(0, r2 - pref2[i] - f2[d]);
                int rem3 = Math.max(0, r3 - pref3[i] - f3[d]);
                int rem5 = Math.max(0, r5 - pref5[i] - f5[d]);
                int rem7 = Math.max(0, r7 - pref7[i] - f7[d]);
                
                String dp_str = dp[rem2][rem3];
                int S = rem5 + rem7 + dp_str.length();
                int K = n - 1 - i;
                
                if (S <= K) {
                    StringBuilder ans = new StringBuilder();
                    ans.append(num.substring(0, i));
                    ans.append(d);
                    
                    int ones = K - S;
                    ans.append("1".repeat(ones));
                    
                    StringBuilder rest = new StringBuilder();
                    rest.append("5".repeat(rem5));
                    rest.append("7".repeat(rem7));
                    rest.append(dp_str);
                    
                    char[] restArr = rest.toString().toCharArray();
                    Arrays.sort(restArr);
                    ans.append(restArr);
                    
                    return ans.toString();
                }
            }
        }
        
        // Out of Bounds Handling Fallback: Answer must be natively compiled by needed primes (longer sequence)
        String dp_str = dp[r2][r3];
        int S_full = r5 + r7 + dp_str.length();
        int L = Math.max(n + 1, S_full);
        
        StringBuilder ans = new StringBuilder();
        ans.append("1".repeat(L - S_full));
        
        StringBuilder rest = new StringBuilder();
        rest.append("5".repeat(r5));
        rest.append("7".repeat(r7));
        rest.append(dp_str);
        
        char[] restArr = rest.toString().toCharArray();
        Arrays.sort(restArr);
        ans.append(restArr);
        
        return ans.toString();
    }
}