class Solution {
public:
    int timer = 0;

    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& nums,
            vector<int>& tin, vector<int>& tout, vector<int>& subXor) {
        tin[node] = timer++;
        subXor[node] = nums[node];
        for (int neigh : adj[node]) {
            if (neigh == parent) continue;
            subXor[node] ^= dfs(neigh, node, adj, nums, tin, tout, subXor);
        }
        tout[node] = timer++;
        return subXor[node];
    }

    bool isAncestor(int u, int v, vector<int>& tin, vector<int>& tout) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n), tout(n), subXor(n);
        int totalXor = dfs(0, -1, adj, nums, tin, tout, subXor);

        vector<int> oriented;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            oriented.push_back(isAncestor(u, v, tin, tout) ? v : u);
        }

        int ans = INT_MAX;
        for (int i = 0; i < oriented.size(); ++i) {
            int u = oriented[i], uXor = subXor[u];
            for (int j = i + 1; j < oriented.size(); ++j) {
                int v = oriented[j], vXor = subXor[v];
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
                int maxX = max({x1, x2, x3});
                int minX = min({x1, x2, x3});
                ans = min(ans, maxX - minX);
            }
        }

        return ans;
    }
};
