class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSets(m);
        for (int i = 0; i < m; i++)
            langSets[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        unordered_set<int> needTeach;
        for (auto &f : friendships) {
            int u = f[0]-1, v = f[1]-1;
            bool canCommunicate = false;
            for (int l : langSets[u]) {
                if (langSets[v].count(l)) { canCommunicate = true; break; }
            }
            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        if (needTeach.empty()) return 0;
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : needTeach) {
                if (!langSets[user].count(lang)) count++;
            }
            ans = min(ans, count);
        }
        return ans;
    }
};
