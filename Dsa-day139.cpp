class Solution {
    using LL = long long;
    static const LL SCALE_FACTOR = 1e9;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<LL, unordered_map<LL, unordered_map<LL, LL>>> mp; // {angle, intersection with x axis, length of edge}
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                LL x1 = points[i][0], y1 = points[i][1];
                LL x2 = points[j][0], y2 = points[j][1];
                LL angle = getAngle(x1, y1, x2, y2);
                LL intersectionPoint = getIntersectionPoint(x1, y1, x2, y2);
                LL length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                mp[angle][intersectionPoint][length]++;
            }
        }
        LL resCnt = 0, parallelogramCnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            auto [cnt, parallelogram] = countTrapezoidsHelper(it->second);
            resCnt += cnt;
            parallelogramCnt += parallelogram;
        }
        return resCnt + parallelogramCnt / 2;
    }
    
    LL getAngle(double x1, double y1, double x2, double y2) {
        return encode(x2 - x1, y2 - y1);
    }

    LL encode(LL x, LL y, LL shift = 2000, LL scale = SCALE_FACTOR) {
        LL gcd = __gcd(x, y);
        x /= gcd;
        y /= gcd;
        return (x + shift) * scale + (y + shift);
    }

    LL getIntersectionPoint(double x1, double y1, double x2, double y2) {
        if (y1 == y2)
            return encode(SCALE_FACTOR / 10, y1);
        // y - y1 = (y2 - y1) / (x2 - x1) * (x - x1)
        // x = x1 - y1 * (x2 - x1) / (y2 - y1), y = 0
        return encode(x1 * (y2 - y1) - y1 * (x2 - x1), y2 - y1, 0);
    }

    pair<LL, LL> countTrapezoidsHelper(unordered_map<LL, unordered_map<LL, LL>>& mpByIntersection) {
        LL cntEdges = 0;
        for (const auto& [intersection, mpByLen] : mpByIntersection)
            for (const auto& [len, curCnt] : mpByLen)
                cntEdges += curCnt;
        LL cntTrapezoid = 0;
        for (auto& [intersection, mpByLen] : mpByIntersection) {
            int cnt = 0;
            for (auto& [len, curCnt] : mpByLen)
                cnt += curCnt;
            cntTrapezoid += cnt * (cntEdges - cnt);
            cntEdges -= cnt;
        }
        // Parallelogram, groupByLen[length][intersection]
        unordered_map<LL, unordered_map<LL, LL>> groupByLenM;
        for (auto& [intersection, mpByLen] : mpByIntersection)
            for (auto& [len, curCnt] : mpByLen)
                groupByLenM[len][intersection] += curCnt;
        LL parallelogramCount = 0;
        for (auto& [len, groupByIntersection] : groupByLenM) {
            int tot = 0;
            for (auto& [intersection, curCnt] : groupByIntersection)
                tot += curCnt;
            for (auto& [intersection, curCnt] : groupByIntersection) {
                parallelogramCount += curCnt * (tot - curCnt);
                tot -= curCnt;
            }
        }
        return { cntTrapezoid - parallelogramCount, parallelogramCount };
    }
};