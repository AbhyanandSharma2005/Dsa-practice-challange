class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> outgoing(n);
        vector<vector<pair<int, int>>> incoming(n);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            outgoing[u].push_back({v, w});
            incoming[v].push_back({u, w});
        }
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        
        set<pair<int, int>> visited;
        
        while (!pq.empty()) {
            auto [cost, node, switchUsed] = pq.top();
            pq.pop();
            
            if (node == n - 1) {
                return cost;
            }
            
            pair<int, int> state = {node, switchUsed};
            if (visited.count(state)) {
                continue;
            }
            visited.insert(state);
            
            for (auto [neighbor, weight] : outgoing[node]) {
                pair<int, int> newState = {neighbor, 0};
                if (!visited.count(newState)) {
                    pq.push({cost + weight, neighbor, 0});
                }
            }
            
            if (switchUsed == 0) {
                for (auto [prevNode, weight] : incoming[node]) {
                    pair<int, int> newState = {prevNode, 0};
                    if (!visited.count(newState)) {
                        pq.push({cost + 2 * weight, prevNode, 0});
                    }
                }
            }
        }
        
        return -1;
    }
};