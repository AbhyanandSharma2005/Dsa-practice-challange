class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> dist(n, -1);
        unordered_map<int, vector<int>> mp;
        mp.reserve(n);

        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for (auto& [_, pos] : mp) {
            int m = pos.size();
            if (m < 2)
                continue;

            for (int i = 0; i < m; i++) {
                int left =
                    (i == 0) ? pos[i] + n - pos[m - 1] : pos[i] - pos[i - 1];
                int right =
                    (i == m - 1) ? pos[0] + n - pos[i] : pos[i + 1] - pos[i];
                dist[pos[i]] = min(left, right);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries)
            ans.push_back(dist[q]);

        return ans;
    }
};