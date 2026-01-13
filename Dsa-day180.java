class Solution {
    public double separateSquares(int[][] squares) {
        long total = 0;
        double maxY = 0;
        for (int[] sq : squares) {
            long l = sq[2];
            total += l * l;
            maxY = Math.max(maxY, sq[1] + l);
        }
        double half = total / 2.0;

        double lo = 0, hi = maxY;
        for (int it = 0; it < 100; it++) {
            double mid = lo + (hi - lo) / 2;
            double areaBelow = 0;
            for (int[] sq : squares) {
                int y = sq[1], l = sq[2];
                if (mid <= y) continue;
                double h = Math.min(mid - y, l);
                areaBelow += h * l;
            }
            if (areaBelow < half) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
}