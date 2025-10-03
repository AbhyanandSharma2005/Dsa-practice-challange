#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }
        int result = 0, maxHeight = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();
            int height = cell[0], x = cell[1], y = cell[2];
            maxHeight = max(maxHeight, height);
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k+1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (heightMap[nx][ny] < maxHeight) result += maxHeight - heightMap[nx][ny];
                    minHeap.push({max(heightMap[nx][ny], maxHeight), nx, ny});
                }
            }
        }
        return result;
    }
};
