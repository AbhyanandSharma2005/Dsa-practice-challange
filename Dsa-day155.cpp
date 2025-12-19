class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> meetingsByTime;
        for (auto& m : meetings) {
            meetingsByTime[m[2]].push_back({m[0], m[1]});
        }
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        parent[firstPerson] = 0;
        
        for (auto& [time, meetingsAtTime] : meetingsByTime) {
            for (auto& [x, y] : meetingsAtTime) {
                unionSets(parent, x, y);
            }
            
            for (auto& [x, y] : meetingsAtTime) {
                if (find(parent, x) != find(parent, 0)) {
                    parent[x] = x;
                }
                if (find(parent, y) != find(parent, 0)) {
                    parent[y] = y;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(parent, i) == find(parent, 0)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py) {
            parent[py] = px;
        }
    }
};