#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int popc(int x){ return __builtin_popcount(x); }
long long modexp(long long a,long long e){ long long r=1;a%=MOD; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n=nums.size();
        vector<long long> fact(m+1), ifact(m+1);
        fact[0]=1; for(int i=1;i<=m;i++) fact[i]=fact[i-1]*i%MOD;
        ifact[m]=modexp(fact[m], MOD-2);
        for(int i=m;i>0;i--) ifact[i-1]=ifact[i]*i%MOD;
        vector<vector<vector<long long>>> pownum(n, vector<vector<long long>>(m+1, vector<long long>(1)));
        vector<vector<long long>> powv(n, vector<long long>(m+1));
        for(int i=0;i<n;i++){
            powv[i][0]=1;
            for(int c=1;c<=m;c++) powv[i][c]=powv[i][c-1]*nums[i]%MOD;
        }
        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(m+1, vector<long long>(m+1,0)));
        dp[0][0][0]=1;
        for(int pos=0; pos<n; pos++){
            vector<vector<vector<long long>>> ndp(m+1, vector<vector<long long>>(m+1, vector<long long>(m+1,0)));
            for(int used=0; used<=m; used++){
                for(int carry=0; carry<=m; carry++){
                    for(int ones=0; ones<=m; ones++){
                        long long cur=dp[used][carry][ones];
                        if(!cur) continue;
                        int maxc = m-used;
                        for(int c=0;c<=maxc;c++){
                            int newused = used + c;
                            int total = carry + c;
                            int bit = total & 1;
                            int newones = ones + bit;
                            int newcarry = total >> 1;
                            long long add = cur * powv[pos][c] % MOD * ifact[c] % MOD;
                            ndp[newused][newcarry][newones] += add;
                            if(ndp[newused][newcarry][newones] >= MOD) ndp[newused][newcarry][newones]-=MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }
        long long ans = 0;
        for(int carry=0; carry<=m; carry++){
            int more = popc(carry);
            for(int ones=0; ones<=m; ones++){
                if(ones + more == k){
                    ans = (ans + dp[m][carry][ones])%MOD;
                }
            }
        }
        ans = ans * fact[m] % MOD;
        return (int)ans;
    }
};
