class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;
        double maxY = 0;
        for (auto& sq : squares) {
            long long l = sq[2];
            total += l * l;
            maxY = max(maxY, sq[1] + (double)l);
        }
        double half = total / 2.0;

        double lo = 0, hi = maxY;
        for (int it = 0; it < 100; ++it) {
            double mid = lo + (hi - lo) / 2;
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], len = sq[2];
                if (mid <= y) continue;
                double h = min(mid - y, (double)len);
                area += h * len;
            }
            if (area < half) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};