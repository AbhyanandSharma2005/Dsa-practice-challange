class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& baskets) {
        n = baskets.size();
        tree.resize(4 * n);
        build(baskets, 0, 0, n - 1);
    }

    void build(vector<int>& baskets, int node, int l, int r) {
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(baskets, 2 * node + 1, l, mid);
        build(baskets, 2 * node + 2, mid + 1, r);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    bool placeFruit(int node, int l, int r, int fruit) {
        if (tree[node] < fruit) return false;

        if (l == r) {
            tree[node] = 0;
            return true;
        }

        int mid = (l + r) / 2;
        bool placed = placeFruit(2 * node + 1, l, mid, fruit);
        if (!placed)
            placed = placeFruit(2 * node + 2, mid + 1, r, fruit);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        return placed;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree seg(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            if (!seg.placeFruit(0, 0, baskets.size() - 1, fruit)) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
