class Solution {
public:
    #define ll long long
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size() , m = tasks.size();
        vector<int>ans(m,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > freeSer;
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>> > busySer;
        for(int i = 0; i < n ; i++){
            freeSer.push({servers[i],i});
        }
        for(int i=0;i<m;i++){
            while(!busySer.empty() && busySer.top().first<=i){
                auto curr=busySer.top();
                busySer.pop();
                freeSer.push({curr.second.first,curr.second.second});
            }
            if(!freeSer.empty()){
                auto curr=freeSer.top();
                freeSer.pop();
                ans[i]=curr.second;
                busySer.push({i+tasks[i],{curr.first,curr.second}});
            }
            else{
                auto curr=busySer.top();
                busySer.pop();
                ans[i]=curr.second.second;
                busySer.push({curr.first+tasks[i],curr.second});
            }
        }
        return ans;
    }
};