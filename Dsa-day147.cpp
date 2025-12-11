class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows; 
        unordered_map<int, vector<int>> cols; 
        
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        
        for (auto& p : rows) sort(p.second.begin(), p.second.end());
        for (auto& p : cols) sort(p.second.begin(), p.second.end());
        
        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            auto& ry = rows[x];
            bool hasLeft  = ry[0] < y;                
            bool hasRight = ry.back() > y;           
            
           
            
            auto& cx = cols[y];
            bool hasAbove = cx[0] < x;              
            bool hasBelow = cx.back() > x;          
            
            if (hasLeft && hasRight && hasAbove && hasBelow) ans++;
        }
        return ans;
    }
};