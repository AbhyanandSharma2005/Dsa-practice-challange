class Solution {
public:
    int binSer(int x, vector<vector<int>>& events){

        int n = events.size();

        int l=0, h=n-1;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;

            if(events[mid][0]>=x){
                ans = mid;
                h=mid-1;
            }else l=mid+1;
        }

        return ans;
    }
    int fun(int i, vector<vector<int>>& events, vector<vector<int>> &dp, int cap){
        int n = events.size();

        if(cap==0)return 0;
        if(i==n)return 0;
        if(dp[i][cap]!=-1)return dp[i][cap];

        int take = events[i][2];
        int ind = binSer(events[i][1]+1, events);
        if(ind!=-1)take+=fun(ind, events, dp, cap-1);

        int notTake = fun(i+1, events, dp, cap);

        return dp[i][cap]=max(take , notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        // vector<vector<int>> dp(n, vector<int>(3, -1));

        // return fun(0, events, dp, 2);

        int ans = INT_MIN;
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        for(int i=0; i<n; i++){
            int res = events[i][2];
            int ind = binSer(events[i][1]+1, events);
            if(ind!=-1)res+=suffixMax[ind];
            ans = max(ans, res);
        }

        return ans;
    }
};