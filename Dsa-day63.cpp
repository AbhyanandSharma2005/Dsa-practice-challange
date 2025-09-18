#include <bits/stdc++.h>
using namespace std;
class TaskManager {
    unordered_map<int,pair<int,int>> mp;
    priority_queue<tuple<int,int,int>> pq;
public:
    TaskManager(vector<vector<int>>& tasks){
        for(auto &x:tasks){
            mp[x[1]]={x[0],x[2]};
            pq.emplace(x[2],x[1],x[1]);
        }
    }
    void add(int userId,int taskId,int priority){
        mp[taskId]={userId,priority};
        pq.emplace(priority,taskId,taskId);
    }
    void edit(int taskId,int newPriority){
        int u=mp[taskId].first;
        mp[taskId]={u,newPriority};
        pq.emplace(newPriority,taskId,taskId);
    }
    void rmv(int taskId){
        mp.erase(taskId);
    }
    int execTop(){
        while(!pq.empty()){
            auto [p,tid,id]=pq.top();pq.pop();
            if(mp.count(tid)&&mp[tid].second==p){
                int u=mp[tid].first;
                mp.erase(tid);
                return u;
            }
        }
        return -1;
    }
};
