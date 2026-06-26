#define ll long long

class SegmentTree{
    vector<long long> tree;
    int n;
public:
    SegmentTree(int m){
        n = m;
        tree.resize(4 * m, 0);
    }

    long long query(int node, int start, int end, int l, int r){
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        long long left = query(2 * node + 1, start, mid, l, r);
        long long right = query(2 * node + 2, mid + 1, end, l, r);

        return left + right;
    }

    void update(int node, int start, int end, int idx, int val){
        if (start == end){
            tree[node] += val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int val){
        update(0, 0, n - 1, idx, val);
    }
};



class Solution {
public:

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ll> pre(n, 0);

        for(int i=0;i<n;i++){
            if(nums[i]==target) nums[i] = 1;
            else nums[i] = -1;
        }
        
        pre[0] = nums[0];
        ll mini = nums[0];

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
            mini = min(mini, pre[i]);
        }

        // coordinate compression
        vector<ll> cpre = pre;
        
        sort(cpre.begin(), cpre.end());
        map<ll,ll> mp;
        int idx = 0;
        for(int i=0;i<cpre.size();i++){
            if(mp.find(cpre[i])==mp.end()){
                mp[cpre[i]] = idx++;
            }
        }

        vector<ll> comp(pre.size());

        for(int i=0;i<pre.size();i++){
            comp[i] = mp[pre[i]];
        }

        long long ans = 0;

        
        SegmentTree t(n);

    

        for(int i=0;i<n;i++){
            if(i==0){
                if(pre[0]==1) ans++;
            }
            else{
                
                int pos = comp[i];
                if(pos>0){
                    ans += t.query(0, pos-1);
                }

                if(pre[i]>0) ans += 1;
            }
            
            t.update(mp[pre[i]], 1);

            

            
        }

        

        return ans;
    }
};