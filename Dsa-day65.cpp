#include <bits/stdc++.h>
using namespace std;

class Router {
    int limit;
    deque<tuple<int,int,int>> q;
    set<tuple<int,int,int>> seen;
    unordered_map<int, vector<int>> dest_map;
public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source,destination,timestamp};
        if(seen.count(key)) return false;
        if((int)q.size() == limit) {
            auto [s,d,t] = q.front(); q.pop_front();
            seen.erase({s,d,t});
            auto &arr = dest_map[d];
            auto it = lower_bound(arr.begin(), arr.end(), t);
            arr.erase(it);
        }
        q.push_back({source,destination,timestamp});
        seen.insert(key);
        auto &arr = dest_map[destination];
        arr.insert(lower_bound(arr.begin(), arr.end(), timestamp), timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [s,d,t] = q.front(); q.pop_front();
        seen.erase({s,d,t});
        auto &arr = dest_map[d];
        auto it = lower_bound(arr.begin(), arr.end(), t);
        arr.erase(it);
        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &arr = dest_map[destination];
        auto l = lower_bound(arr.begin(), arr.end(), startTime);
        auto r = upper_bound(arr.begin(), arr.end(), endTime);
        return r - l;
    }
};
