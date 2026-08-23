#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
int p[MAXN];
int depth[MAXN];
int max_depth[MAXN];
int max1[MAXN];
int max2[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    
    depth[1] = 0;
    max_depth[1] = 0;
    max1[1] = 0;
    max2[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        depth[i] = depth[p[i]] + 1;
        max_depth[i] = depth[i];
        max1[i] = 0;
        max2[i] = 0;
    }
    
    for (int i = n; i >= 2; i--) {
        int u = p[i];
        int d = max_depth[i];
        if (d > max1[u]) {
            max2[u] = max1[u];
            max1[u] = d;
        } else if (d > max2[u]) {
            max2[u] = d;
        }
        if (d > max_depth[u]) {
            max_depth[u] = d;
        }
    }
    
    long long ans = n;
    for (int i = 1; i <= n; i++) {
        if (max2[i] > depth[i]) {
            ans += (max2[i] - depth[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}