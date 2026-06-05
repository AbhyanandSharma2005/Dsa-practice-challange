class Solution {

    static class Pair {
        long cnt, wav;
        Pair(long c, long w) {
            cnt = c;
            wav = w;
        }
    }

    String s;
    Pair[][][][] memo;
    boolean[][][][] vis;

    private Pair dfs(int pos, int p2, int p1, int len, boolean tight, boolean started) {

        if (pos == s.length()) {
            return new Pair(1, 0);
        }

        if (!tight && vis[pos][p2][p1][len]) {
            return memo[pos][p2][p1][len];
        }

        int limit = tight ? s.charAt(pos) - '0' : 9;

        long totalCnt = 0;
        long totalWav = 0;

        for (int d = 0; d <= limit; d++) {

            boolean ntight = tight && (d == limit);

            if (!started && d == 0) {
                Pair child = dfs(pos + 1, 10, 10, 0, ntight, false);
                totalCnt += child.cnt;
                totalWav += child.wav;
                continue;
            }

            if (!started) {
                Pair child = dfs(pos + 1, 10, d, 1, ntight, true);
                totalCnt += child.cnt;
                totalWav += child.wav;
            } else {

                int add = 0;

                if (len >= 2) {
                    if ((p1 > p2 && p1 > d) ||
                        (p1 < p2 && p1 < d)) {
                        add = 1;
                    }
                }

                Pair child = dfs(pos + 1, p1, d, len + 1, ntight, true);

                totalCnt += child.cnt;
                totalWav += child.wav + (long) add * child.cnt;
            }
        }

        Pair ans = new Pair(totalCnt, totalWav);

        if (!tight) {
            vis[pos][p2][p1][len] = true;
            memo[pos][p2][p1][len] = ans;
        }

        return ans;
    }

    private long solve(long x) {
        if (x < 0) return 0;

        s = Long.toString(x);

        memo = new Pair[20][11][11][20];
        vis = new boolean[20][11][11][20];

        return dfs(0, 10, 10, 0, true, false).wav;
    }

    public long totalWaviness(long num1, long num2) {
        return solve(num2) - solve(num1 - 1);
    }
}

      