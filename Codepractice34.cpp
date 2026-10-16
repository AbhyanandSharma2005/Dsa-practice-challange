
#include<bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;

struct segnode{
    long long s_sq=0;
    long long s=0;
};

struct lazynode{
    long long x=0;
};

void build(long long ind,long long low,long long high,long long* p,lazynode* lazy,segnode* seg){
    if(low==high){
        seg[ind].s=p[low];
        seg[ind].s_sq=(p[low]*p[low])%M;
        return;
    }
    long long mid=(low+high)/2;
    build(2*ind+1,low,mid,p,lazy,seg);
    build(2*ind+2,mid+1,high,p,lazy,seg);
    seg[ind].s=(seg[2*ind+1].s+seg[2*ind+2].s)%M;
    seg[ind].s_sq=(seg[2*ind+1].s_sq+seg[2*ind+2].s_sq)%M;
}

void update(long long ind,long long low,long long high,long long l,long long r,long long change,lazynode* lazy,segnode* seg){
    if(lazy[ind].x!=0){
        long long x=lazy[ind].x;
        lazy[ind].x=0;
        seg[ind].s_sq=seg[ind].s_sq+((((high-low+1)*x+M)%M)*x+M)%M+(((2*x+M)%M)*seg[ind].s+M)%M;
        seg[ind].s=(seg[ind].s+(((high-low+1)*x+M)%M)+M)%M;
        if(low!=high){
            lazy[2*ind+1].x+=x;
            lazy[2*ind+2].x+=x;
        }
    }
    if(high<l||low>r){
        return;
    }
    if(l<=low && high<=r){
        long long x=change;
        seg[ind].s_sq=seg[ind].s_sq+((((high-low+1)*x+M)%M)*x+M)%M+(((2*x+M)%M)*seg[ind].s+M)%M;
        seg[ind].s=(seg[ind].s+(((high-low+1)*x+M)%M)+M)%M;
        if(low!=high){
            lazy[2*ind+1].x+=x;
            lazy[2*ind+2].x+=x;
        }
        return;
    }
    long long mid=(low+high)/2;
    update(2*ind+1,low,mid,l,r,change,lazy,seg);
    update(2*ind+2,mid+1,high,l,r,change,lazy,seg);
    seg[ind].s=(seg[2*ind+1].s+seg[2*ind+2].s)%M;
    seg[ind].s_sq=(seg[2*ind+1].s_sq+seg[2*ind+2].s_sq)%M;
}

long long query(long long ind,long long low,long long high,long long l,long long r,lazynode* lazy,segnode* seg){
    if(lazy[ind].x!=0){
        long long x=lazy[ind].x;
        lazy[ind].x=0;
        seg[ind].s_sq=seg[ind].s_sq+((((high-low+1)*x+M)%M)*x+M)%M+(((2*x+M)%M)*seg[ind].s+M)%M;
        seg[ind].s=(seg[ind].s+(((high-low+1)*x+M)%M)+M)%M;
        if(low!=high){
            lazy[2*ind+1].x+=x;
            lazy[2*ind+2].x+=x;
        }
    }
    if(high<l||low>r){
        return 0;
    }
    if(l<=low && high<=r){
        return seg[ind].s_sq;
    }
    long long mid=(low+high)/2;
    long long sum1=query(2*ind+1,low,mid,l,r,lazy,seg);
    long long sum2=query(2*ind+2,mid+1,high,l,r,lazy,seg);
    return (sum1+sum2)%M;
}

class Solution {
public:
    int sumCounts(vector<int>&a) {
        int n=a.size();
        long long p[n];
        set<long long>st;
        map<long long,set<long long>>mp;
        for(long long i=0;i<n;i++){
            st.insert(a[i]);
            p[i]=st.size();
            mp[a[i]].insert(i);
        }
        for(auto it:st)mp[it].insert(n);
        segnode segTree[4*n+10];
        lazynode lazy[4*n+10];
        build(0,0,n-1,p,lazy,segTree);
        long long ans=0;
        for(long long i=0;i<n;i++){
            if(i==0){
                ans+=query(0,0,n-1,i,n-1,lazy,segTree);
                ans%=M;
            }else{
                long long u=*mp[a[i-1]].upper_bound(i-1);
                u--;
                if(u>=i){
                    update(0, 0, n-1, i, u,-1,lazy,segTree);
                }
                ans+=query(0,0,n-1,i,n-1,lazy,segTree);
                ans%=M;
            }
        }
        return (int)ans;
    } 
};