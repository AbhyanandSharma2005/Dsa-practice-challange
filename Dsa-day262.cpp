class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, direction = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> obstacleSet;
        
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;
            } else if (cmd == -2) {
                direction = (direction + 3) % 4;
            } else {
                int dx = directions[direction].first;
                int dy = directions[direction].second;
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (obstacleSet.find({nx, ny}) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxDist;
    }
};