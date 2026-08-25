#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<long long> a(n);
        for(int i=0;i<n;i++) scanf("%lld", &a[i]);
        long long f = 0;
        long long count = 0;
        for(int i=n-1;i>=0;i--){
            f = a[i] + max(f, 0LL);
            if(f > 0) count++;
        }
        printf("%lld\n", count);
    }
    return 0;
