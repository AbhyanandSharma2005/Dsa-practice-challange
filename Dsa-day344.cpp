#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<long long> dp(n + 1, 0);
    
    for (int i = 2; i <= n; i++) {
        long long best = 0;
        for (int j = 1; j < i; j++) {
            long long option1 = (long long)j * (i - j);
            long long option2 = (long long)j * dp[i - j];
            best = max(best, max(option1, option2));
        }
        dp[i] = best;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}