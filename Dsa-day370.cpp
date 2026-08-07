#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int r2 = 0, r3 = 0, r5 = 0, r7 = 0;
        
        while (temp % 2 == 0) { r2++; temp /= 2; }
        while (temp % 3 == 0) { r3++; temp /= 3; }
        while (temp % 5 == 0) { r5++; temp /= 5; }
        while (temp % 7 == 0) { r7++; temp /= 7; }
        
        // If t has prime factors other than 2, 3, 5, or 7, no zero-free digit combinations can satisfy it.
        if (temp > 1) {
            return "-1";
        }
        
        int n = num.size();
        int f2[] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int f3[] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int f5[] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int f7[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
        
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        bool hasZero = false;
        int first_zero = -1;
        
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0) {
                hasZero = true;
                if (first_zero == -1) first_zero = i;
            }
            pref2[i+1] = pref2[i] + f2[d];
            pref3[i+1] = pref3[i] + f3[d];
            pref5[i+1] = pref5[i] + f5[d];
            pref7[i+1] = pref7[i] + f7[d];
        }
        
        // Already zero-free and completely divisible -> No increment required
        if (!hasZero && pref2[n] >= r2 && pref3[n] >= r3 && pref5[n] >= r5 && pref7[n] >= r7) {
            return num;
        }
        
        int max_r2 = 50;
        int max_r3 = 30; // Fits since max factors under bounds: 2^46 < 10^14 and 3^29 < 10^14
        vector<vector<string>> dp(max_r2 + 1, vector<string>(max_r3 + 1, string(100, '9')));
        dp[0][0] = "";
        char digits_to_try[] = {'2', '3', '4', '6', '8', '9'};
        
        for (int i = 0; i <= max_r2; ++i) {
            for (int j = 0; j <= max_r3; ++j) {
                if (i == 0 && j == 0) continue;
                string best = string(100, '9');
                for (char d : digits_to_try) {
                    int d_val = d - '0';
                    int ni = max(0, i - f2[d_val]);
                    int nj = max(0, j - f3[d_val]);
                    
                    if (dp[ni][nj].length() < 100) {
                        string cand = dp[ni][nj] + d;
                        sort(cand.begin(), cand.end());
                        if (cand.length() < best.length() || (cand.length() == best.length() && cand < best)) {
                            best = cand;
                        }
                    }
                }
                dp[i][j] = best;
            }
        }
        
        int start_i = (first_zero == -1) ? n - 1 : first_zero;
        
        // Try modifying bounded from the back to maintain maximum possible prefix
        for (int i = start_i; i >= 0; --i) {
            int orig_d = num[i] - '0';
            int start_d = orig_d + 1;
            
            for (int d = start_d; d <= 9; ++d) {
                int rem2 = max(0, r2 - pref2[i] - f2[d]);
                int rem3 = max(0, r3 - pref3[i] - f3[d]);
                int rem5 = max(0, r5 - pref5[i] - f5[d]);
                int rem7 = max(0, r7 - pref7[i] - f7[d]);
                
                const string& dp_str = dp[rem2][rem3];
                int S = rem5 + rem7 + dp_str.length();
                int K = n - 1 - i;
                
                if (S <= K) {
                    string ans = num.substr(0, i) + to_string(d);
                    int ones = K - S;
                    ans += string(ones, '1');
                    string rest = string(rem5, '5') + string(rem7, '7') + dp_str;
                    sort(rest.begin(), rest.end());
                    ans += rest;
                    return ans;
                }
            }
        }
        
        // Out of Bounds Handling Fallback: Answer must be at least one digit longer natively compiled by needed primes
        const string& dp_str = dp[r2][r3];
        int S_full = r5 + r7 + dp_str.length();
        int L = max(n + 1, S_full);
        
        string ans = string(L - S_full, '1');
        string rest = string(r5, '5') + string(r7, '7') + dp_str;
        sort(rest.begin(), rest.end());
        ans += rest;
        return ans;
    }
};