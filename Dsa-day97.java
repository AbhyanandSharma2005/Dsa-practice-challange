import java.util.*;

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length;
        if (n == 0) return 0;

        TreeMap<Long, Integer> freq = new TreeMap<>();
        for (int v : nums) freq.put((long)v, freq.getOrDefault((long)v, 0) + 1);

        TreeMap<Long, Integer> events = new TreeMap<>();
        for (int v : nums) {
            long l = (long)v - k;
            long r = (long)v + k;
            events.put(l, events.getOrDefault(l, 0) + 1);
            long after = r + 1L;
            events.put(after, events.getOrDefault(after, 0) - 1);
        }

        long[] uniques = new long[freq.size()];
        int ui = 0;
        for (long x : freq.keySet()) uniques[ui++] = x;

        int ans = 1;
        long currCover = 0;
        Iterator<Map.Entry<Long,Integer>> it = events.entrySet().iterator();
        List<Map.Entry<Long,Integer>> evList = new ArrayList<>(events.entrySet());

        int eidx = 0;
        int uidx = 0; 
        while (eidx < evList.size()) {
            long pos = evList.get(eidx).getKey();
            while (eidx < evList.size() && evList.get(eidx).getKey() == pos) {
                currCover += evList.get(eidx).getValue();
                eidx++;
            }

            long nextPos = (eidx < evList.size()) ? evList.get(eidx).getKey() : Long.MAX_VALUE;

            if (pos <= nextPos - 1) {
                int candidate = (int)Math.min(currCover, numOperations);
                ans = Math.max(ans, candidate);

                while (uidx < uniques.length && uniques[uidx] >= pos && uniques[uidx] <= nextPos - 1) {
                    int cEqual = freq.get(uniques[uidx]);
                    int ach = (int)Math.min(currCover, (long)cEqual + numOperations);
                    ans = Math.max(ans, ach);
                    uidx++;
                }
            }
        }

        while (uidx < uniques.length) {
            int cEqual = freq.get(uniques[uidx]);
            ans = Math.max(ans, Math.min(n, cEqual + numOperations)); 
            uidx++;
        }

        return Math.min(ans, n);
    }
}