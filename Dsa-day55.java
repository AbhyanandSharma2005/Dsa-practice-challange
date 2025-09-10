import java.util.*;

class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        int m = languages.length;
        List<Set<Integer>> langSets = new ArrayList<>();
        for (int[] langs : languages) {
            Set<Integer> set = new HashSet<>();
            for (int l : langs) set.add(l);
            langSets.add(set);
        }
        Set<Integer> needTeach = new HashSet<>();
        for (int[] f : friendships) {
            int u = f[0]-1, v = f[1]-1;
            boolean canCommunicate = false;
            for (int l : langSets.get(u)) {
                if (langSets.get(v).contains(l)) { canCommunicate = true; break; }
            }
            if (!canCommunicate) {
                needTeach.add(u);
                needTeach.add(v);
            }
        }
        if (needTeach.isEmpty()) return 0;
        int ans = Integer.MAX_VALUE;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : needTeach) {
                if (!langSets.get(user).contains(lang)) count++;
            }
            ans = Math.min(ans, count);
        }
        return ans;
    }
}
