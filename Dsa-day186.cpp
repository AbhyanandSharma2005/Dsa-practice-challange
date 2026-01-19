class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                             - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return prefix[r2+1][c2+1] - prefix[r2+1][c1] 
                 - prefix[r1][c2+1] + prefix[r1][c1];
        };
        
        int left = 0, right = min(m, n);
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool possible = false;
            
            for (int i = 0; i <= m - mid; ++i) {
                for (int j = 0; j <= n - mid; ++j) {
                    if (getSum(i, j, i + mid - 1, j + mid - 1) <= threshold) {
                        possible = true;
                        goto next;
                    }
                }
            }
            next:
            if (possible) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};