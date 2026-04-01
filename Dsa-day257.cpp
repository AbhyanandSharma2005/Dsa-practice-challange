class Solution {
using ll = long long;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<ll,ll> mp;
        vector<tuple<ll,ll,ll>> temp;
        for(int i=0;i<positions.size();++i){
            int v = 0;
            if(directions[i] == 'R') v++;
            temp.push_back({positions[i],healths[i],v});
        }
        sort(temp.begin(),temp.end());
        stack<tuple<ll,ll,ll>> st;
        for(int i=0;i<temp.size();++i){
            auto [pos,wt,dir] = temp[i];
            if(st.empty()){
                if(dir == 0){
                    mp[pos] = wt;
                }else st.push({pos,wt,dir});
            }else{
                if(dir == 1) st.push({pos,wt,dir});
                else{
                    if(get<1>(st.top()) == wt){
                        mp[get<0>(st.top())] = 0;
                        st.pop();
                        mp[pos] = 0;
                        continue;
                    }
                    while(!st.empty() && get<1>(st.top()) < wt){
                        mp[get<0>(st.top())] = 0;
                        st.pop();
                        wt--;
                    }
                    if(!st.empty() && get<1>(st.top()) == wt){
                        mp[get<0>(st.top())] = 0;
                        st.pop();
                        mp[pos] = 0;
                        continue;
                    }
                    if(st.empty()) mp[pos] = wt;
                    else{
                        mp[pos] = 0;
                        auto [pos2,wt2,dir2] = st.top();
                        st.pop();
                        wt2--;
                        mp[pos2] = wt2;
                        st.push({pos2,wt2,dir2});
                    }
                }

            }
        }
        while(!st.empty()){
            mp[get<0>(st.top())] = get<1>(st.top());
            st.pop();
        }
        vector<int> ans;
        for(int i: positions) {
            if(mp[i] > 0) ans.push_back(mp[i]);
        }
        return ans;
    }
};