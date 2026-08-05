class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> sus(n, false);
        vector<vector<int>> g(n);
        for (auto& it : invocations)
            g[it[0]].push_back(it[1]);

        queue<int> que;
        que.push(k);
        sus[k] = true;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (int u : g[v])
                if (!sus[u]) { sus[u] = true; que.push(u); }
        }

        for (auto& it : invocations)
            if (!sus[it[0]] && sus[it[1]]) {
                vector<int> ans(n);
                for (int i = 0; i < n; i++) ans[i] = i;
                return ans;
            }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!sus[i]) ans.push_back(i);
        return ans;
    }
};