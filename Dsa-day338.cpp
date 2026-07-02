class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>mincost(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>dq;

        mincost [0][0] = grid[0][0];
        dq.push_front({0,0});

        int drow [] = {1,-1,0,0,};
        int dcol [] = {0,0,-1,1};
        
        while(!dq.empty()){
            auto[r,c] = dq.front();
            dq.pop_front();

            for(int i =0; i<4; i++){
                int nr = r+ drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n) {
                    int cost = grid[nr][nc];
                    if(mincost[r][c]+cost <mincost[nr][nc]){
                        mincost[nr][nc] = mincost[r][c] + cost;
                        if (cost == 0){
                            dq.push_front({nr,nc});
                        }else {
                            dq.push_back({nr,nc});
                        }

                    }
                }

            }

        }
        return mincost[m-1][n-1] < health;

    }
   
};