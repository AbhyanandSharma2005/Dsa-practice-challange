class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;
        char[] word = new char[n];
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] == 0) {
                if (c >= 26) return "";
                word[i] = (char)('a' + c++);
            }
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (word[j] == 0) word[j] = word[i];
                    else if (word[j] != word[i]) return "";
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int expected;
                if (word[i] == word[j]) {
                    expected = (i == n-1 || j == n-1) ? 1 : lcp[i+1][j+1] + 1;
                } else {
                    expected = 0;
                }
                if (lcp[i][j] != expected) return "";
            }
        }
        return new String(word);
    }
}