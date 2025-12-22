class Solution {
public:
    int dp[101][101];
    int n, l;
    int find(int i, int last, vector<string>& strs) {
        if (i >= l)
            return 0;
        if (dp[i][last] != -1)
            return dp[i][last];
        int res = 1 + find(i + 1, last, strs);
        bool isOk = true;
        for (int j = 0; j < n; j++)
            if (strs[j][last] > strs[j][i]) {
                isOk = false;
                break;
            }
        if (isOk)
            res = min(res, find(i + 1, i, strs));
        return dp[i][last] = res;
    }
    int minDeletionSize(vector<string>& strs) {
        memset(dp, -1, sizeof(dp));
        n = strs.size(), l = strs[0].size();
        int res = l;
        for (int i = 0; i < l; i++)
            res = min(res, (i) + find(i + 1, i, strs));
        return res;
    }
};