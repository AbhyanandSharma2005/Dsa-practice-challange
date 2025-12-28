class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (auto& row : grid) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            count += n - left;
        }
        return count;
    }
};