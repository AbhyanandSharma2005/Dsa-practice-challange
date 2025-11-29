class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        int r = sum % k;
        return r;                     // if r == 0 returns 0, otherwise returns r
    }
};