#include <vector>
#include <iostream>

class Solution {
public:
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        std::vector<std::vector<int>> prefixX(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> prefixY(rows, std::vector<int>(cols, 0));
        
        int count = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                
                if (grid[i][j] == 'X') {
                    prefixX[i][j] = 1;
                }
                if (i > 0) {
                    prefixX[i][j] += prefixX[i-1][j];
                }
                if (j > 0) {
                    prefixX[i][j] += prefixX[i][j-1];
                }
                if (i > 0 && j > 0) {
                    prefixX[i][j] -= prefixX[i-1][j-1];
                }
                
                if (grid[i][j] == 'Y') {
                    prefixY[i][j] = 1;
                }
                if (i > 0) {
                    prefixY[i][j] += prefixY[i-1][j];
                }
                if (j > 0) {
                    prefixY[i][j] += prefixY[i][j-1];
                }
                if (i > 0 && j > 0) {
                    prefixY[i][j] -= prefixY[i-1][j-1];
                }
                
                if (prefixX[i][j] > 0 && prefixX[i][j] == prefixY[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};