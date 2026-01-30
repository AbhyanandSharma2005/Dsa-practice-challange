class Solution {
public:
    //TC = O(N∗M∗Log(M))   &&  SC = O(M)
    typedef long long ll;
    ll INF = 1e15;

    unordered_map<string, vector<pair<string, ll>>> graph;

    string sourceStr;
    string targetStr;

    set<int> validLength;

    vector<ll> dp;

    //Dijkstra Memoization (IMP)
    //start -> end - > answer
    unordered_map<string, unordered_map<string, ll>> dpDijkstra;

    ll dijkstra(string &st, string &end) {
        if(dpDijkstra[st].count(end)) {
            return dpDijkstra[st][end];
        }

        priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq; //{cost, neighbour}
        unordered_map<string, ll> dist; //src to string ka cost store

        dist[st] = 0;
        pq.push({0, st});

        while(pq.size() > 0) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto &e : graph[node]) {
                string adjNode = e.first;
                ll edgeCost = e.second;

                if(!dist.count(adjNode) ||dist[adjNode] > currCost + edgeCost) { //Edge Relaxitation
                    dist[adjNode] = currCost + edgeCost;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dpDijkstra[st][end] = dist.count(end) ? dist[end] : INF;
    }

    ll dfs(int idx) {
        if(idx >= sourceStr.length()) { //BASE CASE
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        ll minCost = INF;

        if(sourceStr[idx] == targetStr[idx]) {
            minCost = dfs(idx+1);
        }

        for(auto &len : validLength) { //Try Possible All Length
            if(idx+len > sourceStr.length()) { //No more Substring
                break;
            }

            string srcSub = sourceStr.substr(idx, len);
            string tarSub = targetStr.substr(idx, len);

            if(!graph.count(srcSub)) {
                continue;
            }

            ll minPathCost = dijkstra(srcSub, tarSub);

            if(minPathCost == INF) {
                continue;
            }

            minCost = min( minCost, minPathCost + dfs(idx+len));
        }

        return dp[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = original.size();

        sourceStr = source;
        targetStr = target;

        dp.assign(10001, -1);

        for(int i = 0; i < n; i++) {
            graph[original[i]].push_back({changed[i], cost[i]});
        }

        for(string &str : original) {
            validLength.insert(str.length());
        }

        ll ans = dfs(0);

        return ans != INF ? ans : -1;
    }
};