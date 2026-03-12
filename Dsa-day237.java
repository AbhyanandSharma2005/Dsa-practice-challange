class Solution {
    class DSU {
        int[] parent, rank;

        DSU(int n) {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        boolean union(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if (pa == pb)
                return false;

            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pb] < rank[pa])
                parent[pb] = pa;
            else {
                parent[pb] = pa;
                rank[pa]++;
            }

            return true;
        }
    }

    private boolean check(int n, int[][] edges, int k, int mid) {

        DSU dsu = new DSU(n);
        List<int[]> upgrade = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 1) {
                if (s < mid) return false;
                dsu.union(u, v);
            } else {
                if (s >= mid) {
                    dsu.union(u, v);
                } else if (2 * s >= mid) {
                    upgrade.add(e);
                }
            }
        }

        for (int[] e : upgrade) {
            if (k == 0) break;
            if (dsu.union(e[0], e[1])) k--;
        }

        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return false;
        }

        return true;
    }

    public int maxStability(int n, int[][] edges, int k) {

        Arrays.sort(edges, (a, b) -> b[2] - a[2]); // sort descending

        DSU dsu = new DSU(n);

        for (int[] e : edges) {
            if (e[3] == 1) {
                if (!dsu.union(e[0], e[1]))
                    return -1;
            }
        }

        int left = 1;
        int right = 200000;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (check(n, edges, k, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
        
    }
}