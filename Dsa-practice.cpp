#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    sort(a, a + 3);
    
    long long ans = min(a[2] - a[0], a[1]);
    
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