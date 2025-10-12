import java.util.*;
public class Solution {
    static final long MOD = 1000000007L;
    static long modexp(long a,long e){ long r=1;a%=MOD; while(e>0){ if((e&1)==1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }
    static int popc(int x){ return Integer.bitCount(x); }
    public int magicalSum(int m, int k, int[] nums) {
        int n = nums.length;
        long[] fact = new long[m+1];
        long[] ifact = new long[m+1];
        fact[0]=1;
        for(int i=1;i<=m;i++) fact[i]=fact[i-1]*i%MOD;
        ifact[m]=modexp(fact[m], MOD-2);
        for(int i=m;i>0;i--) ifact[i-1]=ifact[i]*i%MOD;
        long[][] powv = new long[n][m+1];
        for(int i=0;i<n;i++){
            powv[i][0]=1;
            for(int c=1;c<=m;c++) powv[i][c]=powv[i][c-1]*nums[i]%MOD;
        }
        long[][][] dp = new long[m+1][m+1][m+1];
        dp[0][0][0]=1;
        for(int pos=0; pos<n; pos++){
            long[][][] ndp = new long[m+1][m+1][m+1];
            for(int used=0; used<=m; used++){
                for(int carry=0; carry<=m; carry++){
                    for(int ones=0; ones<=m; ones++){
                        long cur = dp[used][carry][ones];
                        if(cur==0) continue;
                        int maxc = m-used;
                        for(int c=0;c<=maxc;c++){
                            int newused = used + c;
                            int total = carry + c;
                            int bit = total & 1;
                            int newones = ones + bit;
                            int newcarry = total >> 1;
                            long add = cur * powv[pos][c] % MOD * ifact[c] % MOD;
                            ndp[newused][newcarry][newones] += add;
                            if(ndp[newused][newcarry][newones] >= MOD) ndp[newused][newcarry][newones]-=MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }
        long ans = 0;
        for(int carry=0; carry<=m; carry++){
            int more = popc(carry);
            for(int ones=0; ones<=m; ones++){
                if(ones + more == k) ans = (ans + dp[m][carry][ones])%MOD;
            }
        }
        ans = ans * fact[m] % MOD;
        return (int)ans;
    }
}
