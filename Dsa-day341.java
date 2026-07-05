class Solution {

    class State {
        int score;
        int ways;

        public State(int s, int w) {
            score = s;
            ways = w;
        }
    }

    public int[] pathsWithMaxScore(List<String> board) {

        int n = board.size();
        int m = board.get(0).length();
        final int MOD = 1_000_000_007;

        State[][] dp = new State[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = new State(-1, 0);
            }
        }

        // Base case : S
        dp[n - 1][m - 1] = new State(0, 1);

        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1)
                    continue;

                char ch = board.get(i).charAt(j);

                if (ch == 'X')
                    continue;

                State down = (i + 1 < n) ? dp[i + 1][j] : null;
                State right = (j + 1 < m) ? dp[i][j + 1] : null;
                State diag = (i + 1 < n && j + 1 < m) ? dp[i + 1][j + 1] : null;

                State[] next = { down, right, diag };

                int maxScore = -1;

                for (State s : next) {
                    if (s != null) {
                        maxScore = Math.max(maxScore, s.score);
                    }
                }

                if (maxScore == -1)
                    continue;

                int ways = 0;

                for (State s : next) {
                    if (s != null && s.score == maxScore) {
                        ways = (ways + s.ways) % MOD;
                    }
                }

                int value = 0;

                if (Character.isDigit(ch))
                    value = ch - '0';

                dp[i][j].score = maxScore + value;
                dp[i][j].ways = ways;
            }
        }

        if (dp[0][0].score == -1)
            return new int[] {0, 0};

        return new int[] {
            dp[0][0].score,
            dp[0][0].ways
        };
    }
}