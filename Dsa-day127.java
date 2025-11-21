class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        
        // Initialize first and last occurrences
        for (int i = 0; i < 26; i++) {
            first[i] = -1;
            last[i] = -1;
        }
        
        // Record first and last index for each character
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        int ans = 0;
        
        // For each possible middle character b (0 to 25)
        for (int b = 0; b < 26; b++) {
            if (first[b] == -1) continue; // b doesn't appear
            
            int left = first[b];
            int right = last[b];
            
            if (right - left < 2) continue; // need at least one char between first and last b
            
            // Count unique characters strictly between first[b] and last[b]
            boolean[] seen = new boolean[26];
            for (int i = left + 1; i < right; i++) {
                int idx = s.charAt(i) - 'a';
                if (!seen[idx]) {
                    seen[idx] = true;
                    ans++;
                }
            }
        }
        
        return ans;
    }
}