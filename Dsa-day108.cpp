class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& w : walls) grid[w[0]][w[1]] = -1;
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& g : guards) {
            for (auto& d : dirs) {
                int r=g[0]+d.first, c=g[1]+d.second;
                while (r>=0 && r<m && c>=0 && c<n && grid[r][c]!=-1 && grid[r][c]!=1) {
                    if (grid[r][c]==0) grid[r][c]=2;
                    r+=d.first; c+=d.second;
                }
            }
        }
        int cnt=0;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (grid[i][j]==0) cnt++;
        return cnt;
    }
};
