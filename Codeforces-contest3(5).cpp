#include <bits/stdc++.h>
using namespace std;
 
static inline int readInt(const char *&p) {
    while (*p && (*p < '0' || *p > '9') && *p != '-') ++p;
    bool neg = false;
    if (*p == '-') { neg = true; ++p; }
    int x = 0;
    while (*p >= '0' && *p <= '9') { x = x * 10 + (*p - '0'); ++p; }
    return neg ? -x : x;
}
 
int n;
vector<int> offsetArr, adj;
vector<int> dist1, parent1, order1;
vector<int> distA, parentA, orderA;
vector<int> depthBuf, parentBuf, orderBuf;
 
// BFS from `start`, filling dist/parent/order (order also acts as the queue via index pointer)
static void bfsFull(int start, vector<int> &dist, vector<int> &parent, vector<int> &order) {
    fill(dist.begin(), dist.end(), -1);
    order.clear();
    dist[start] = 0;
    order.push_back(start);
    for (size_t head = 0; head < order.size(); ++head) {
        int x = order[head];
        int dx = dist[x] + 1;
        int lo = offsetArr[x], hi = offsetArr[x + 1];
        for (int k = lo; k < hi; ++k) {
            int y = adj[k];
            if (dist[y] == -1) {
                dist[y] = dx;
                parent[y] = x;
                order.push_back(y);
            }
        }
    }
}
 
// BFS from `root` excluding the edge to `excl`; returns the set of depths that are
// "extremal" (either the max depth, or a branch point with >=2 children reaching max depth).
static void computeS(int root, int excl, vector<int> &depth, vector<int> &parent, vector<int> &order,
                      vector<int> &branchCount, vector<unsigned char> &reachMx, set<int> &Sset) {
    fill(depth.begin(), depth.end(), -1);
    order.clear();
    depth[root] = 0;
    depth[excl] = -2; // sentinel so BFS never traverses through it
    order.push_back(root);
    for (size_t head = 0; head < order.size(); ++head) {
        int x = order[head];
        int dx = depth[x] + 1;
        int lo = offsetArr[x], hi = offsetArr[x + 1];
        for (int k = lo; k < hi; ++k) {
            int y = adj[k];
            if (depth[y] == -1) {
                depth[y] = dx;
                parent[y] = x;
                order.push_back(y);
            }
        }
    }
    int mx = depth[order.back()];
    fill(branchCount.begin(), branchCount.end(), 0);
    fill(reachMx.begin(), reachMx.end(), 0);
    for (int node : order) {
        if (depth[node] == mx) reachMx[node] = 1;
    }
    for (int i = (int)order.size() - 1; i > 0; --i) {
        int node = order[i];
        if (reachMx[node]) {
            int p = parent[node];
            reachMx[p] = 1;
            branchCount[p]++;
        }
    }
    Sset.clear();
    Sset.insert(mx);
    for (int node : order) {
        if (branchCount[node] >= 2) Sset.insert(depth[node]);
    }
}
 
int main() {
    // Read entire stdin into a buffer for fast parsing.
    static char buf[1 << 25];
    size_t total = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[total] = '\0';
    const char *p = buf;
 
    int t = readInt(p);
    string out;
    out.reserve(1 << 20);
 
    vector<int> us, vs, deg, fillpos;
 
    for (int tc = 0; tc < t; ++tc) {
        n = readInt(p);
        deg.assign(n + 1, 0);
        us.assign(n - 1, 0);
        vs.assign(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int u = readInt(p), v = readInt(p);
            us[i] = u; vs[i] = v;
            deg[u]++; deg[v]++;
        }
 
        offsetArr.assign(n + 2, 0);
        for (int i = 1; i <= n; ++i) offsetArr[i + 1] = offsetArr[i] + deg[i];
        adj.assign(2 * (n - 1), 0);
        fillpos = offsetArr;
        for (int i = 0; i < n - 1; ++i) {
            int u = us[i], v = vs[i];
            adj[fillpos[u]++] = v;
            adj[fillpos[v]++] = u;
        }
 
        dist1.assign(n + 1, -1); parent1.assign(n + 1, 0); order1.reserve(n + 1);
        bfsFull(1, dist1, parent1, order1);
        int A = 1, bestD = dist1[1];
        for (int i = 2; i <= n; ++i) if (dist1[i] > bestD) { bestD = dist1[i]; A = i; }
 
        distA.assign(n + 1, -1); parentA.assign(n + 1, 0); orderA.reserve(n + 1);
        bfsFull(A, distA, parentA, orderA);
        int B = A, bestD2 = 0;
        for (int i = 1; i <= n; ++i) if (distA[i] > bestD2) { bestD2 = distA[i]; B = i; }
        int D = bestD2;
        int m = (D - 1) / 2;
 
        int cur = B;
        while (distA[cur] > m + 1) cur = parentA[cur];
        int v_node = cur;
        int u_node = parentA[cur];
 
        depthBuf.assign(n + 1, -1); parentBuf.assign(n + 1, 0); orderBuf.reserve(n + 1);
        vector<int> branchCount(n + 1, 0);
        vector<unsigned char> reachMx(n + 1, 0);
 
        set<int> SU, SV;
        computeS(u_node, v_node, depthBuf, parentBuf, orderBuf, branchCount, reachMx, SU);
        computeS(v_node, u_node, depthBuf, parentBuf, orderBuf, branchCount, reachMx, SV);
 
        set<int> result;
        for (int a : SU) for (int b : SV) result.insert(a + b + 1);
 
        out += to_string(result.size());
        out += '\n';
        bool first = true;
        for (int val : result) {
            if (!first) out += ' ';
            first = false;
            out += to_string(val);
        }
        out += '\n';
    }
 
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}