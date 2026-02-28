class Solution {
public:
    long long ans = 0;
    int mod = 1e9 + 7;

    void addDecimalValue(int ele) {
        bool mark = false;
        for (int i = 31; i >= 0; i--) {
            if (ele & (1 << i)) {
                ans = (1LL * ans * 2 + 1) % mod;
                mark = true;
            } else if (mark) {
                ans = (1LL * ans * 2) % mod;
            }
        }
        return;
    }

    int concatenatedBinary(int n) {

        for (int ele = 1; ele <= n; ele++) {
            addDecimalValue(ele);
        }
        return ans;
    }
};