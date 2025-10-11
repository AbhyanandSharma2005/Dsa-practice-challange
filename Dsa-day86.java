import java.util.*;

class Solution {
    public long maximumTotalDamage(int[] power) {
        if (power == null || power.length == 0) {
            return 0;
        }

        // 1. Count frequencies and calculate total damage for each unique power
        Map<Integer, Long> totalDamageMap = new HashMap<>();
        for (int p : power) {
            totalDamageMap.put(p, totalDamageMap.getOrDefault(p, 0L) + (long)p);
        }

        // 2. Get sorted unique power values
        List<Integer> uniquePower = new ArrayList<>(totalDamageMap.keySet());
        Collections.sort(uniquePower);

        int n = uniquePower.size();
        if (n == 0) {
            return 0;
        }

        // 3. Dynamic Programming
        // dp[i] is the maximum total damage considering spells with damage up to uniquePower.get(i)
        long[] dp = new long[n];

        // Base case: i = 0
        dp[0] = totalDamageMap.get(uniquePower.get(0));

        for (int i = 1; i < n; ++i) {
            int currentP = uniquePower.get(i);
            long currentDamage = totalDamageMap.get(currentP);

            // Choice 1: Skip all spells with damage currentP
            long skipDamage = dp[i - 1];

            // Choice 2: Cast all spells with damage currentP
            long castDamage = currentDamage;

            // Find the largest index j < i such that uniquePower.get(j) < currentP - 2
            int j = i - 1;
            while (j >= 0 && uniquePower.get(j) >= currentP - 2) {
                j--;
            }

            if (j >= 0) {
                castDamage += dp[j];
            }

            dp[i] = Math.max(skipDamage, castDamage);
        }

        return dp[n - 1];
    }
}