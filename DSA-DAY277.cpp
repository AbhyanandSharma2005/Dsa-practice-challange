class Solution {
public:
    int bfs(int curr, vector<unordered_set<int>> &g, vector<int> &vis, vector<int>& source, vector<int>& target){
        unordered_map<int, int> mp;
        queue<int> q;
        q.push(curr);
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(vis[curr]) continue;

            vis[curr] = 1;
            mp[source[curr]]++;
            mp[target[curr]]--;

            for(int i:g[curr]){
                if(!vis[i]) q.push(i);
            }
        }

        int ans = 0;
        for(auto i:mp){
            ans += abs(i.second);
        }

        return ans/2;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<unordered_set<int>> g(n);
        for(auto i : allowedSwaps){
            g[i[0]].insert(i[1]);
            g[i[1]].insert(i[0]);
        }

        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            count += bfs(i,g,vis, source, target);
        }

        return count;
    }
};