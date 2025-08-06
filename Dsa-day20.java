class Solution {
    class SegmentTree {
        int[] tree;
        int n;

        SegmentTree(int[] baskets) {
            n = baskets.length;
            tree = new int[4 * n];
            build(baskets, 0, 0, n - 1);
        }

        void build(int[] baskets, int node, int l, int r) {
            if (l == r) {
                tree[node] = baskets[l];
                return;
            }
            int mid = (l + r) / 2;
            build(baskets, 2 * node + 1, l, mid);
            build(baskets, 2 * node + 2, mid + 1, r);
            tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
        }

        boolean placeFruit(int node, int l, int r, int fruit) {
            if (tree[node] < fruit) return false;

            if (l == r) {
                tree[node] = 0; 
                return true;
            }

            int mid = (l + r) / 2;
            boolean placed = placeFruit(2 * node + 1, l, mid, fruit);
            if (!placed)
                placed = placeFruit(2 * node + 2, mid + 1, r, fruit);

            tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
            return placed;
        }
    }

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        SegmentTree seg = new SegmentTree(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            if (!seg.placeFruit(0, 0, baskets.length - 1, fruit)) {
                unplaced++;
            }
        }

        return unplaced;
    }
}
