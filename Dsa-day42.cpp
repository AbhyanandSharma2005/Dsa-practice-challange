class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int start = 0; start < n; start++) {
            vector<int> d1, d2;
            int i = start, j = 0;
            while (i < n && j < n) d1.push_back(grid[i++][j++]);
            sort(d1.rbegin(), d1.rend());
            i = start; j = 0; int idx = 0;
            while (i < n && j < n) grid[i++][j++] = d1[idx++];
            
            if (start > 0) {
                i = 0; j = start;
                while (i < n && j < n) d2.push_back(grid[i++][j++]);
                sort(d2.begin(), d2.end());
                i = 0; j = start; idx = 0;
                while (i < n && j < n) grid[i++][j++] = d2[idx++];
            }
        }
        return grid;
    }
};
