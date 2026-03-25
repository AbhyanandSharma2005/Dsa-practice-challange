class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for (auto& row : grid)
            for (int val : row)
                total += val;
        
        if (total % 2 != 0) return false;
        long long half = total / 2;
        
        long long prefix = 0;
        for (int i = 0; i < (int)grid.size() - 1; i++) {
            for (int val : grid[i]) prefix += val;
            if (prefix == half) return true;
        }
        
        prefix = 0;
        for (int j = 0; j < (int)grid[0].size() - 1; j++) {
            for (int i = 0; i < (int)grid.size(); i++) prefix += grid[i][j];
            if (prefix == half) return true;
        }
        
        return false;
    }
};