class Solution {
    public double separateSquares(int[][] squares) {
        List<Double> xCoords = new ArrayList<>();
        for (int[] sq : squares) {
            xCoords.add((double) sq[0]);
            xCoords.add((double) (sq[0] + sq[2]));
        }
        
        double[] xs = xCoords.stream().distinct().sorted().mapToDouble(d -> d).toArray();
        
        List<Event> events = new ArrayList<>();
        for (int[] sq : squares) {
            events.add(new Event(sq[1], sq[0], sq[0] + sq[2], 1));
            events.add(new Event(sq[1] + sq[2], sq[0], sq[0] + sq[2], -1));
        }
        Collections.sort(events, (a, b) -> Double.compare(a.y, b.y));
        
        int n = xs.length;
        SegmentTree tree = new SegmentTree(n, xs);
        
        double totalArea = 0;
        double prevY = events.get(0).y;
        List<Strip> strips = new ArrayList<>();
        
        for (Event e : events) {
            if (e.y > prevY) {
                double height = e.y - prevY;
                double width = tree.query();
                totalArea += width * height;
                strips.add(new Strip(prevY, height, width));
                prevY = e.y;
            }
            int leftIdx = Arrays.binarySearch(xs, e.x1);
            int rightIdx = Arrays.binarySearch(xs, e.x2);
            tree.update(leftIdx, rightIdx, e.type);
        }
        
        double targetArea = totalArea / 2.0;
        double accumulated = 0;
        
        for (Strip strip : strips) {
            if (accumulated + strip.height * strip.width >= targetArea) {
                return strip.y + (targetArea - accumulated) / strip.width;
            }
            accumulated += strip.height * strip.width;
        }
        
        return 0;
    }
    
    class Event {
        double y, x1, x2;
        int type;
        
        Event(double y, double x1, double x2, int type) {
            this.y = y;
            this.x1 = x1;
            this.x2 = x2;
            this.type = type;
        }
    }
    
    class Strip {
        double y, height, width;
        
        Strip(double y, double height, double width) {
            this.y = y;
            this.height = height;
            this.width = width;
        }
    }
    
    class SegmentTree {
        int[] count;
        double[] length;
        double[] xs;
        int size;
        
        SegmentTree(int n, double[] xs) {
            this.size = n;
            this.xs = xs;
            this.count = new int[4 * n];
            this.length = new double[4 * n];
        }
        
        void update(int left, int right, int delta) {
            update(1, 0, size - 1, left, right, delta);
        }
        
        void update(int node, int l, int r, int ql, int qr, int delta) {
            if (qr <= l || r <= ql) return;
            
            if (ql <= l && r <= qr) {
                count[node] += delta;
            } else {
                int mid = (l + r) / 2;
                update(node * 2, l, mid, ql, qr, delta);
                update(node * 2 + 1, mid, r, ql, qr, delta);
            }
            
            if (count[node] > 0) {
                length[node] = xs[r] - xs[l];
            } else if (r - l == 1) {
                length[node] = 0;
            } else {
                length[node] = length[node * 2] + length[node * 2 + 1];
            }
        }
        
        double query() {
            return length[1];
        }
    }
}