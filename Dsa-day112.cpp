#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<bool> online(c + 1, true);
        vector<vector<int>> adj(c + 1);
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<priority_queue<int, vector<int>, greater<int>>> substations;
        unordered_map<int, int> station_lookup;
        function<void(int, int)> dfs = [&](int node, int idx) {
            if (station_lookup.count(node)) return;
            station_lookup[node] = idx;
            substations[idx].push(node);
            for (int nei : adj[node]) dfs(nei, idx);
        };

        for (int i = 1; i <= c; i++) {
            if (!station_lookup.count(i)) {
                substations.push_back({});
                dfs(i, (int)substations.size() - 1);
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int t = q[0], x = q[1];
            int sid = station_lookup[x];
            auto &pq = substations[sid];
            if (t == 2) {
                online[x] = false;
                while (!pq.empty() && !online[pq.top()]) pq.pop();
            } else {
                if (online[x]) ans.push_back(x);
                else {
                    while (!pq.empty() && !online[pq.top()]) pq.pop();
                    ans.push_back(pq.empty() ? -1 : pq.top());
                }
            }
        }
        return ans;
    }
};
