class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        def get_slope_inter(p1, p2):
            dy, dx = p2[1]-p1[1], p2[0] - p1[0]
            if dx < 0:
                dx, dy = -dx, -dy
            if dx == 0:
                dy = 1
            g = gcd(dy, dx)
            dy, dx = dy//g, dx//g
            return (dy, dx), dy*p1[0] - dx*p1[1]
            
        def get_mid(p1, p2):
            mx, my = p1[0] + p2[0], p1[1] + p2[1]
            return (mx, my)

        counter1, counter2, counter3, counter4 = [defaultdict(int) for _ in range(4)]
        for i, p1 in enumerate(points):
            for p2 in points[i+1:]:
                (slope, inter), mid = get_slope_inter(p1, p2), get_mid(p1, p2)
                counter1[slope] += 1
                counter2[(slope, inter)] += 1
                counter3[mid] += 1
                counter4[(mid, slope)] += 1

        return sum(c*(c-1)//2 for c in counter1.values()) \
                - sum(c*(c-1)//2 for c in counter2.values()) \
                - sum(c*(c-1)//2 for c in counter3.values()) \
                + sum(c*(c-1)//2 for c in counter4.values())
        return res

        