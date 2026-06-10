#include <bits/stdc++.h>
using namespace std;

class MINSGTree{
    public:
    vector<int> seg;
    MINSGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx, int low, int high, vector<int> &arr){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low+high)>>1;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
    int query(int idx, int low,int high, int l, int r){
        if(low>=l && high<=r){
            return seg[idx];
        }
        if(high<l || low>r){
            return INT_MAX;
        }
        int mid = (low+high)>>1;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
};

class MAXSGTree{
    public:
    vector<int> seg;
    MAXSGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx, int low, int high, vector<int> &arr){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low+high)>>1;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }
    int query(int idx, int low,int high, int l, int r){
        if(low>=l && high<=r){
            return seg[idx];
        }
        if(high<l || low>r){
            return INT_MIN;
        }
        int mid = (low+high)>>1;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);
        return max(left,right);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        MINSGTree sg1(n);
        MAXSGTree sg2(n);
        sg1.build(0,0,n-1,nums);
        sg2.build(0,0,n-1,nums);

        priority_queue<tuple<int,int,int>> pq;
        long long ans = 0;
        
        for(int l = 0; l<n; l++){
            int min = sg1.query(0,0,n-1,l,n-1);
            int max = sg2.query(0,0,n-1,l,n-1);
            pq.push({max-min,l,n-1});
        }
        
        while(!pq.empty() && k>0){
            auto [val,l,r] = pq.top();
            ans += val;
            pq.pop();
            if(l<r){
                int min = sg1.query(0,0,n-1,l,r-1);
                int max = sg2.query(0,0,n-1,l,r-1);
                pq.push({max-min,l,r-1});
            }
            k--;
        }
        return ans;
    }
};