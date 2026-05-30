class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n + 5, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MX = 50000;

        set<int> obs;
        obs.insert(0);

        SegmentTree st(MX + 1);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto it = obs.upper_bound(x);

                int nxt = (it == obs.end()) ? MX : *it;
                int prv = *prev(it);

                obs.insert(x);

                st.update(1, 0, MX, x, x - prv);

                if (nxt != MX) {
                    st.update(1, 0, MX, nxt, nxt - x);
                }
            }

            else {

                int x = q[1];
                int sz = q[2];

                auto it = obs.upper_bound(x);

                int mxGap = 0;
                int last = 0;

                if (it != obs.begin()) {
                    --it;
                    last = *it;
                    mxGap = st.query(1, 0, MX, 0, last);
                }

                mxGap = max(mxGap, x - last);

                ans.push_back(mxGap >= sz);
            }
        }

        return ans;
    }
};