int seg[4*100001]{};
long long mod = 1e9+7;
class Solution {
public:
    int query(int idx, int left, int right, int lr, int rr){
        if(left>=lr && right<=rr){
            return seg[idx];
        }
        if(left>rr || right<lr) return 0;
        int mid = (left+right)>>1;
        int lAns = query(2*idx+1, left, mid, lr,rr);
        int rAns = query(2*idx+2, mid+1, right, lr,rr);
        return lAns^rAns;
    }

    void build(int idx, int left, int right, vector<int>& num){
        if(left==right) {
            seg[idx] = num[left];
            return;
        }
        int mid = (left+right)>>1;
        build(2*idx+1,left,mid, num);
        build(2*idx+2,mid+1,right, num);
        seg[idx]=seg[2*idx+1]^seg[2*idx+2];
    }

    void update(int idx, int left, int right, int node, int val){
        if(left==right){
            seg[idx]=val;
            return;
        }
        int mid = (left+right)>>1;

        if(node<=mid && node>=left) update(2*idx+1, left, mid, node, val);
        else update(2*idx+2, mid+1, right, node, val);

        seg[idx]=seg[2*idx+1]^seg[2*idx+2];
    }

    //brutteee works too

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size()-1;
        build(0,0,n,nums);
        for(const auto q:queries){
            int idx=q[0];
            while(idx<=q[1]){
                int val = ((long long)nums[idx]*q[3])%mod;
                update(0,0,n,idx,val);
                nums[idx]=val;
                idx+=q[2];
            }
        }
        return seg[0];
    }
};