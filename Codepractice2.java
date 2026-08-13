class Solution {
    struct Node {
        int pre;
        int suf;
        int max_len;
    };
    
    vector<Node> tree;
    string str;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        merge(node, start, mid, end);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }
        merge(node, start, mid, end);
    }

    void merge(int node, int start, int mid, int end) {
        int left = 2 * node;
        int right = 2 * node + 1;
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        tree[node].pre = tree[left].pre;
        tree[node].suf = tree[right].suf;
        tree[node].max_len = max(tree[left].max_len, tree[right].max_len);

        if (str[mid] == str[mid + 1]) {
            if (tree[left].pre == leftSize) {
                tree[node].pre += tree[right].pre;
            }
            if (tree[right].suf == rightSize) {
                tree[node].suf += tree[left].suf;
            }
            tree[node].max_len = max(tree[node].max_len, tree[left].suf + tree[right].pre);
        }
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);
        build(1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            str[idx] = queryCharacters[i];
            update(1, 0, n - 1, idx);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};