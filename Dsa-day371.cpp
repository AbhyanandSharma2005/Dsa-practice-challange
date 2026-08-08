#include <iostream>
#include <random>

using namespace std;

struct Node {
    long long val;
    long long lazy;
    int priority;
    int l, r;
};

const int MAXN = 200005;
Node tr[MAXN];
int root, node_cnt;
mt19937 rng(1337);

int newNode(long long val) {
    tr[++node_cnt] = {val, 0, (int)rng(), 0, 0};
    return node_cnt;
}

void push(int u) {
    if (u && tr[u].lazy) {
        tr[u].val += tr[u].lazy;
        if (tr[u].l) tr[tr[u].l].lazy += tr[u].lazy;
        if (tr[u].r) tr[tr[u].r].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}

void split(int u, long long x, int& l, int& r) {
    if (!u) {
        l = r = 0;
        return;
    }
    push(u);
    if (tr[u].val <= x) {
        split(tr[u].r, x, tr[u].r, r);
        l = u;
    } else {
        split(tr[u].l, x, l, tr[u].l);
        r = u;
    }
}

void merge(int& u, int l, int r) {
    if (!l || !r) {
        u = l ? l : r;
        return;
    }
    push(l); push(r);
    if (tr[l].priority > tr[r].priority) {
        merge(tr[l].r, tr[l].r, r);
        u = l;
    } else {
        merge(tr[r].l, l, tr[r].l);
        u = r;
    }
}

long long get_max(int u) {
    if (!u) return 0;
    push(u);
    if (tr[u].r) return get_max(tr[u].r);
    return tr[u].val;
}

void solve() {
    int n;
    cin >> n;
    root = 0;
    node_cnt = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        int L = 0, R = 0;
        split(root, x, L, R);
        if (R) {
            tr[R].lazy += x;
        }
        int mid = newNode(x);
        merge(root, L, mid);
        merge(root, root, R);
    }
    cout << get_max(root) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}