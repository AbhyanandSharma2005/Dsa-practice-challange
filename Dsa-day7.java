class Solution {
    int timer = 0;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        int[] tin = new int[n];
        int[] tout = new int[n];
        int[] subXor = new int[n];
        int totalXor = dfs(0, -1, nums, adj, tin, tout, subXor);

        List<Integer> oriented = new ArrayList<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            if (isAncestor(u, v, tin, tout)) {
                oriented.add(v);
            } else {
                oriented.add(u);
            }
        }

        int minScore = Integer.MAX_VALUE;
        for (int i = 0; i < oriented.size(); i++) {
            int u = oriented.get(i), uXor = subXor[u];
            for (int j = i + 1; j < oriented.size(); j++) {
                int v = oriented.get(j), vXor = subXor[v];
                int x1, x2, x3;
                if (isAncestor(u, v, tin, tout)) {
                    x1 = vXor;
                    x2 = uXor ^ vXor;
                    x3 = totalXor ^ uXor;
                } else if (isAncestor(v, u, tin, tout)) {
                    x1 = uXor;
                    x2 = vXor ^ uXor;
                    x3 = totalXor ^ vXor;
                } else {
                    x1 = uXor;
                    x2 = vXor;
                    x3 = totalXor ^ uXor ^ vXor;
                }
                int max = Math.max(x1, Math.max(x2, x3));
                int min = Math.min(x1, Math.min(x2, x3));
                minScore = Math.min(minScore, max - min);
            }
        }

        return minScore;
    }

    private int dfs(int node, int parent, int[] nums, List<List<Integer>> adj,
                    int[] tin, int[] tout, int[] subXor) {
        tin[node] = timer++;
        subXor[node] = nums[node];
        for (int neighbor : adj.get(node)) {
            if (neighbor != parent) {
                subXor[node] ^= dfs(neighbor, node, nums, adj, tin, tout, subXor);
            }
        }
        tout[node] = timer++;
        return subXor[node];
    }

    private boolean isAncestor(int u, int v, int[] tin, int[] tout) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
}
