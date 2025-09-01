import java.util.*;
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        for (int[] c : classes) {
            double p = c[0], t = c[1];
            pq.offer(new double[]{gain(p, t), p, t});
        }
        while (extraStudents-- > 0) {
            double[] cur = pq.poll();
            double p = cur[1] + 1, t = cur[2] + 1;
            pq.offer(new double[]{gain(p, t), p, t});
        }
        double sum = 0;
        while (!pq.isEmpty()) {
            double[] cur = pq.poll();
            sum += cur[1] / cur[2];
        }
        return sum / classes.length;
    }
    private double gain(double p, double t) {
        return (p + 1) / (t + 1) - p / t;
    }
}
