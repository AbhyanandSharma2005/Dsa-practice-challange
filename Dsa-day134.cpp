class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long total = values[node];
            for (int child : adj[node]) {
                if (child != parent) {
                    long long sub = dfs(child, node);
                    total += sub;
                }
            }
            if (total % k == 0) {
                ++ans;
                return 0;
            }
            return total;
        };
        dfs(0, -1);
        return ans;
    }
};