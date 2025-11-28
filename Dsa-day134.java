class Solution {
    private List<Integer>[] adj;
    private int ans;
    private long k;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        this.k = k;
        adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        ans = 0;
        dfs(0, -1, values);
        return ans;
    }
    
    private long dfs(int node, int parent, int[] values) {
        long total = values[node];
        for (int child : adj[node]) {
            if (child != parent) {
                long sub = dfs(child, node, values);
                total += sub;
            }
        }
        if (total % k == 0) {
            ans++;
            return 0;
        }
        return total;
    }
}