import java.util.*;

class Solution {
    public int maxPartitionsAfterOperations(String s, int k) {
        int n = s.length();
        List<Object[]> prefix = new ArrayList<>(n);
        List<Object[]> suffix = new ArrayList<>(n);

        int partitions = 0, lastStart = 0;
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            prefix.add(new Object[]{partitions, lastStart, new HashSet<>(set)});
            set.add(s.charAt(i));
            if (set.size() > k) {
                partitions++;
                lastStart = i;
                set.clear();
                set.add(s.charAt(i));
            }
        }

        partitions = 0;
        lastStart = n - 1;
        set.clear();
        for (int i = n - 1; i >= 0; i--) {
            suffix.add(0, new Object[]{partitions, lastStart, new HashSet<>(set)});
            set.add(s.charAt(i));
            if (set.size() > k) {
                partitions++;
                lastStart = i;
                set.clear();
                set.add(s.charAt(i));
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            Set<Character> merged = new HashSet<>((Set<Character>) prefix.get(i)[2]);
            merged.addAll((Set<Character>) suffix.get(i)[2]);
            int contribution;
            if (merged.size() < k || k >= 26)
                contribution = 1;
            else if (((Set<Character>) prefix.get(i)[2]).size() == k &&
                     ((Set<Character>) suffix.get(i)[2]).size() == k &&
                     merged.size() < 26)
                contribution = 3;
            else
                contribution = 2;
            ans = Math.max(ans, (int) prefix.get(i)[0] + (int) suffix.get(i)[0] + contribution);
        }

        return ans;
    }
}
