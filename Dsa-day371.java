class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        
        // suf[i] will store the maximum length of a suffix of word2
        // that is a subsequence of word1[i...n-1].
        int[] suf = new int[n + 1];
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                j--;
            }
            suf[i] = m - 1 - j;
        }
        
        int[] ans = new int[m];
        j = 0;
        boolean changed = false;
        
        for (int i = 0; i < n && j < m; ++i) {
            if (word1.charAt(i) == word2.charAt(j)) {
                // Exact match: always take it to minimize index and preserve the change
                ans[j] = i;
                j++;
            } else if (!changed && suf[i + 1] >= m - j - 1) {
                // Can use the 1 allowed change here because the remaining characters
                // of word2 can be matched exactly in the remaining characters of word1.
                changed = true;
                ans[j] = i;
                j++;
            }
        }
        
        // If we successfully mapped all characters of word2, return the sequence
        if (j == m) {
            return ans;
        }
        
        // Otherwise, no such valid sequence of indices exists
        return new int[0];
    }
}