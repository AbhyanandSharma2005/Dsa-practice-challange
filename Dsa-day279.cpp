#define ll long long int  
class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();

        unordered_map<ll,vector<ll>> m, p;


        for(int i = 0; i < n; i++)
        {
            m[(ll)nums[i]].push_back(i);

            if(m[(ll)nums[i]].size() == 1)
                p[(ll)nums[i]].push_back((ll)i);
            else  
                p[(ll)nums[i]].push_back((ll)i + (ll)p[nums[i]].back());

        }

        vector<ll> ans(n,0);


        for(auto [x, v1]: m)
        {
            int k = v1.size();
            // cout<<x<<endl;

            vector<ll> v2 = p[x];

            if(k == 1)
                continue;

            for(int i = 0; i < k; i++)
            {
                ll left = (i > 0 ? v2[i-1] : 0);
                ll right = (i < k - 1 ? v2[k - 1] - v2[i] : 0);

                ll l = (i == 0 ? 0 : i);
                ll r = (i == k - 1 ? 0 : k - i - 1);

                ll a = (l == 0 ? 0 : (l * v1[i] - left));
                ll b =  (r == 0 ? 0 : (right - r * v1[i]));

                ll curr = a + b;

                ans[v1[i]] = curr; 

                // cout<<left<<" "<<right<<endl;
                // cout<<l<<" "<<r<<endl;
                // cout<<a<<" "<<b<<endl;
                // cout<<curr<<endl;
                // cout<<endl;

            }

        }

        return ans;
        
    }
};