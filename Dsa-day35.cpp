class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) heights[j] += 1;
                else heights[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                int minH = heights[j];
                for (int k = j; k >= 0 && minH > 0; k--) {
                    minH = min(minH, heights[k]);
                    ans += minH;
                }
            }
        }
        return ans;
    }
};
