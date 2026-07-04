class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& r : roads) {
            int u = r[0], v = r[1], c = r[2];
            adj[u].emplace_back(c, v);
            adj[v].emplace_back(c, u);
        }
        int ans = 1e9, root = 1;
        vector<bool> vis(n+1, false); vis[root] = true;
        queue<int> q; q.push(root);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto [c, v] : adj[u]) {
                ans = min(ans, c);
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        
        return ans;
    }
};