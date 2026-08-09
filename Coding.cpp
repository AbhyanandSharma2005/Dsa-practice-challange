#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (cin >> n >> m) {
        vector<long long> a(m);
        for (long long i = 0; i < m; ++i) {
            cin >> a[i];
        }
        
        sort(a.rbegin(), a.rend());
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (long long i = 0; i < n; ++i) {
            pq.push(0);
        }
        
        for (long long i = 0; i < m; ++i) {
            long long current_min = pq.top();
            pq.pop();
            pq.push(current_min + a[i]);
        }
        
        vector<long long> res(n);
        for (long long i = 0; i < n; ++i) {
            res[i] = pq.top();
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        
        for (long long i = 0; i < n; ++i) {
            cout << res[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}