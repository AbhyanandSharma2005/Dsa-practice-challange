class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minW = workerTimes[0];
        int maxW = minW;
        int minIdx = 0;
        
        for (int i = 1; i < workerTimes.size(); i++) {
            int w = workerTimes[i];
            if (w < minW) {
                minW = w;
                minIdx = i;
            } else if (w > maxW) {
                maxW = w;
            }
        }
        
        if (minIdx != 0) {
            workerTimes[minIdx] = workerTimes[0];
            workerTimes[0] = minW;
        }
        
        long long length = workerTimes.size();
        long long ceilH = (mountainHeight + length - 1) / length;
        long long tasks = ceilH * (ceilH + 1) / 2LL;
        long long l = tasks * minW;
        long long r = tasks * maxW;
        long long ans = r;
        
        while (l <= r) {
            long long mid = l + ((r - l) >> 1);
            long long mid2 = mid << 1;
            long long sum = 0;
            
            for (int i = 0; i < length; i++) {
                long long val = mid2 / workerTimes[i];
                if (val >= 2) {
                    long long x = (long long)sqrt(val);
                    if (x * (x + 1) > val) x--;
                    sum += x;
                    if (sum >= mountainHeight) break;
                }
            }
            
            if (sum >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};