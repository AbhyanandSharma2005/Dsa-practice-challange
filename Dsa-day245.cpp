class Solution {
public:
    int diffbymat(int x1, int y1, int x2, int y2, vector < vector <int>> &mat) {
        multiset <int> ms;
        for (int i=x1;i<x2;i++) {
            for (int j=y1;j<y2;j++) {
                ms.insert(mat[i][j]);
            }
        }
        int mini = 1e9;
        int a = *ms.begin();
        int temp = 0;
        ms.erase(ms.begin());
        while (!ms.empty()) {
            temp = *ms.begin();
            ms.erase(ms.begin());
            if (temp != a) mini = min(mini, abs(temp - a));
            a = temp;
        }
        if (temp == 0) return 0;
        return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector <vector<int>> res;
        for (int i=0;i<m;i++) {
            if (i + k > m) break;
            vector <int> temp;
            for (int j=0;j<n;j++) {
                if (j + k > n) break;
                int ans = diffbymat(i, j, i + k, j + k, mat);
                temp.push_back(ans);
            }
            res.push_back(temp);
        }
        return res;
    }
};