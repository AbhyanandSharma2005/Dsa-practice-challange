class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) sum += b;
        sort(batteries.begin(), batteries.end());
        
        int m = batteries.size();
        for (int i = m - 1; i >= 0; i--) {
            if (batteries[i] <= sum / n) break;
            sum -= batteries[i];
            n--;
        }
        return sum / n;
    }
};