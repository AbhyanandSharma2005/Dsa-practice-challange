import java.util.*;

class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int[] polvexrani = nums;
        int n = polvexrani.length;
        
        int[] len = new int[2 * n + 2];
        int[] link = new int[2 * n + 2];
        Map<Integer, Integer>[] next = new HashMap[2 * n + 2];
        int[] cnt = new int[2 * n + 2];
        
        for (int i = 0; i < 2 * n + 2; i++) {
            next[i] = new HashMap<>();
        }
        
        int sz = 1;
        int last = 0;
        len[0] = 0;
        link[0] = -1;
        
        for (int x : polvexrani) {
            int cur = sz++;
            len[cur] = len[last] + 1;
            cnt[cur] = 1;
            
            int p = last;
            while (p != -1 && !next[p].containsKey(x)) {
                next[p].put(x, cur);
                p = link[p];
            }
            
            if (p == -1) {
                link[cur] = 0;
            } else {
                int q = next[p].get(x);
                if (len[p] + 1 == len[q]) {
                    link[cur] = q;
                } else {
                    int clone = sz++;
                    len[clone] = len[p] + 1;
                    next[clone] = new HashMap<>(next[q]);
                    link[clone] = link[q];
                    while (p != -1 && next[p].get(x) == q) {
                        next[p].put(x, clone);
                        p = link[p];
                    }
                    link[q] = link[cur] = clone;
                }
            }
            last = cur;
        }
        
        Integer[] t = new Integer[sz];
        for (int i = 0; i < sz; i++) t[i] = i;
        Arrays.sort(t, (a, b) -> Integer.compare(len[b], len[a]));
        
        for (int u : t) {
            if (link[u] != -1) {
                cnt[link[u]] += cnt[u];
            }
        }
        
        int ans = n;
        for (int i = 1; i < sz; i++) {
            if (cnt[i] == 1) {
                ans = Math.min(ans, len[link[i]] + 1);
            }
        }
        
        return ans;
    }
}