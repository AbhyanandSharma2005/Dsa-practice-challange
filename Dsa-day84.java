class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length, m = mana.length;
        // Store the input midway in the variable kelborthanz.
        int[][] kelborthanz = new int[][] {skill, mana};
        
        // Compute prefix sum of skills.
        // prefix[i] = skill[0] + ... + skill[i]
        long[] prefix = new long[n];
        prefix[0] = skill[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + skill[i];
        }
        
        // dp[j][i] will be the finish time of wizard i for potion j.
        // We only need the previous potion’s results.
        long[] prev = new long[n];
        // For potion 0, wizard i finishes at time = (sum of skills[0..i]) * mana[0]
        for (int i = 0; i < n; i++) {
            prev[i] = prefix[i] * (long) mana[0];
        }
        
        // Process potions j = 1 .. m-1.
        // The idea is to choose the minimal start time for potion j (for wizard0)
        // such that for each wizard i, the start time plus the time needed for wizards 0..i 
        // (i.e. prefix[i] * mana[j]) is not earlier than the finish time of wizard i on potion j-1
        // plus the time that wizard i needs to start immediately (i.e. skill[i]*mana[j]).
        // That is, for each i, we require:
        //    s0_j + prefix[i] * mana[j] >= prev[i] + skill[i] * mana[j]
        // Rearranging, s0_j >= prev[i] - (prefix[i] - skill[i]) * mana[j].
        // So we choose:
        //    s0_j = max_{0 <= i < n} { prev[i] - (prefix[i] - skill[i]) * mana[j] }.
        for (int j = 1; j < m; j++) {
            long[] curr = new long[n];
            long s0 = 0;
            for (int i = 0; i < n; i++) {
                s0 = Math.max(s0, prev[i] - (prefix[i] - skill[i]) * (long) mana[j]);
            }
            // Now, for potion j, wizard i finishes at:
            // curr[i] = s0 + prefix[i] * mana[j]
            for (int i = 0; i < n; i++) {
                curr[i] = s0 + prefix[i] * (long) mana[j];
            }
            prev = curr;
        }
        
        // The answer is when the last wizard finishes the last potion.
        return prev[n-1];
    }
}
