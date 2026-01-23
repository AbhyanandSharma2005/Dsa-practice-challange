import java.util.PriorityQueue;

class Solution {
    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;

        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nums[i];

        int[] L = new int[n];
        int[] R = new int[n];
        boolean[] alive = new boolean[n];

        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
            alive[i] = true;
        }

        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i + 1]) bad++;
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (x, y) -> x[0] != y[0]
                ? Long.compare(x[0], y[0])
                : Long.compare(x[1], y[1])
        );

        for (int i = 0; i + 1 < n; i++) {
            pq.offer(new long[]{a[i] + a[i + 1], i});
        }

        int ops = 0;

        while (bad > 0) {
            long[] cur = pq.poll();
            long sum = cur[0];
            int i = (int) cur[1];
            int j = R[i];

            if (j >= n || !alive[i] || !alive[j] || a[i] + a[j] != sum)
                continue;

            int li = L[i];
            int rj = R[j];

            if (li >= 0 && alive[li] && a[li] > a[i]) bad--;
            if (a[i] > a[j]) bad--;
            if (rj < n && alive[rj] && a[j] > a[rj]) bad--;

            a[i] += a[j];
            alive[j] = false;
            ops++;

            R[i] = rj;
            if (rj < n) L[rj] = i;

            if (li >= 0 && alive[li] && a[li] > a[i]) bad++;
            if (rj < n && alive[rj] && a[i] > a[rj]) bad++;

            if (li >= 0 && alive[li])
                pq.offer(new long[]{a[li] + a[i], li});
            if (rj < n && alive[rj])
                pq.offer(new long[]{a[i] + a[rj], i});
        }

        return ops;
    }
}