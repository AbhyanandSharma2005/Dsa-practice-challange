class Solution {
    public int numSub(String s) {
        final int MOD = 1000000007;
        long ans = 0;
        long cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                cnt++;
            } else {
                ans = (ans + cnt * (cnt + 1) / 2) % MOD;
                cnt = 0;
            }
        }
        ans = (ans + cnt * (cnt + 1) / 2) % MOD;
        return (int) ans;
    }
}