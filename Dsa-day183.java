import java.util.*;

class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        final long MOD = 1000000007L;

        List<Integer> h = new ArrayList<>();
        List<Integer> v = new ArrayList<>();

        h.add(1);
        h.add(m);
        for (int x : hFences) h.add(x);

        v.add(1);
        v.add(n);
        for (int x : vFences) v.add(x);

        Collections.sort(h);
        Collections.sort(v);

        Set<Integer> hs = new HashSet<>();
        for (int i = 0; i < h.size(); i++)
            for (int j = i + 1; j < h.size(); j++)
                hs.add(h.get(j) - h.get(i));

        long ans = -1;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                int d = v.get(j) - v.get(i);
                if (hs.contains(d)) ans = Math.max(ans, d);
            }
        }

        if (ans == -1) return -1;
        return (int)((ans * ans) % MOD);
    }
}
