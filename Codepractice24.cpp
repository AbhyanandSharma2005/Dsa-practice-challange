#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);

        long long budget = n;
        long long count = 0;

        for (int j = 0; j <= 20 && budget > 0; j++) {
            long long cost = 1LL << j;
            if (cost > budget) break;
            long long take = min(k, budget / cost);
            count += take;
            budget -= take * cost;
        }

        printf("%lld\n", count);
    }
    return 0;
}