class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type;
        Event(double y, double x1, double x2, int type) : y(y), x1(x1), x2(x2), type(type) {}
    };
    
    struct Strip {
        double y, height, width;
        Strip(double y, double h, double w) : y(y), height(h), width(w) {}
    };
    
    vector<double> xs;
    vector<int> cnt;
    vector<double> seg;
    
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        
        if (ql <= l && r <= qr) {
            cnt[node] += val;
        } else {
            int m = (l + r) / 2;
            update(node * 2, l, m, ql, qr, val);
            update(node * 2 + 1, m, r, ql, qr, val);
        }
        
        if (cnt[node] > 0) {
            seg[node] = xs[r] - xs[l];
        } else if (r - l == 1) {
            seg[node] = 0;
        } else {
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
    }
    
    double separateSquares(vector<vector<int>>& squares) {
        set<double> xSet;
        for (auto& sq : squares) {
            xSet.insert((double)sq[0]);
            xSet.insert((double)(sq[0] + sq[2]));
        }
        xs.assign(xSet.begin(), xSet.end());
        
        vector<Event> events;
        for (auto& sq : squares) {
            events.push_back(Event(sq[1], sq[0], sq[0] + sq[2], 1));
            events.push_back(Event(sq[1] + sq[2], sq[0], sq[0] + sq[2], -1));
        }
        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.y < b.y;
        });
        
        int n = xs.size();
        cnt.assign(4 * n, 0);
        seg.assign(4 * n, 0);
        
        double totalArea = 0;
        double prevY = events[0].y;
        vector<Strip> strips;
        
        for (auto& e : events) {
            if (e.y > prevY) {
                double height = e.y - prevY;
                double width = seg[1];
                totalArea += width * height;
                strips.push_back(Strip(prevY, height, width));
                prevY = e.y;
            }
            int leftIdx = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int rightIdx = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();
            update(1, 0, n - 1, leftIdx, rightIdx, e.type);
        }
        
        double targetArea = totalArea / 2.0;
        double accumulated = 0;
        
        for (auto& strip : strips) {
            if (accumulated + strip.height * strip.width >= targetArea) {
                return strip.y + (targetArea - accumulated) / strip.width;
            }
            accumulated += strip.height * strip.width;
        }
        
        return 0;
    }
};