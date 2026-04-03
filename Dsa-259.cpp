class Solution {
public:
    int dp[100005][2];

    int fun(vector<vector<int>>& robo, vector<int>& walls, int in, int prevRight) {
        int n = robo.size();
        if (in >= n) return 0;
        if (dp[in][prevRight] != -1) return dp[in][prevRight];

        int x = robo[in][0];
        int d = robo[in][1];
        int ans = 0;

        int rDis = x+d;
        if(in+1 < n){
            rDis = min(rDis , robo[in+1][0] - 1);
        }
        int c = (int)(upper_bound(walls.begin() , walls.end(), rDis) - lower_bound(walls.begin() , walls.end() , x));
        ans = max(ans , c + fun(robo, walls, in+1, 1));

        int l = x - d;
        int r = x;

        if(in > 0){
            l = max(l , robo[in-1][0] + 1);
        }

        if(prevRight && in > 0){
            int l2 = robo[in-1][0];
            int r2 = robo[in-1][0] + robo[in-1][1];

            if(l <= r2){
                l = r2+1;
            }
        }

        if(l<=r){
            c = upper_bound(walls.begin(), walls.end(), r) - lower_bound(walls.begin(), walls.end(), l);
            ans = max(ans , c + fun(robo, walls, in+1, 0));
        }

        return dp[in][prevRight] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> robo;

        for (int i = 0; i < (int)robots.size(); i++){
            robo.push_back({robots[i], distance[i]});
        }

        sort(robo.begin(), robo.end());
        sort(walls.begin(), walls.end());
        
        return fun(robo, walls, 0, 0);
    }
};