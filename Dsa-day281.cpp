class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long P = 4LL * side;
        int n = points.size();
        vector<long long> a;

        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) a.push_back(x);
            else if (x == side) a.push_back(side + y);
            else if (y == side) a.push_back(2LL * side + (side - x));
            else a.push_back(3LL * side + (side - y));
        }

        sort(a.begin(), a.end());
        vector<long long> b(2*n);
        for(int i=0;i<n;i++){
            b[i]=a[i];
            b[i+n]=a[i]+P;
        }

        auto ok = [&](long long d){
            vector<int> nxt(2*n);
            int j=0;
            for(int i=0;i<2*n;i++){
                if(j<i) j=i;
                while(j<2*n && b[j]-b[i]<d) j++;
                nxt[i]=j;
            }

            for(int i=0;i<n;i++){
                int cnt=1;
                int cur=i;
                while(cnt<k && cur< i+n){
                    cur=nxt[cur];
                    cnt++;
                }
                if(cnt>=k && cur<i+n && b[cur]-b[i]<=P-d) return true;
            }
            return false;
        };

        long long l=0,r=P,ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(ok(mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
};