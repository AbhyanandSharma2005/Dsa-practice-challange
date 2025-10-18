class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = LLONG_MIN;
        int count = 0;
        for (auto x : nums) {
            long long low = (long long)x - k, high = (long long)x + k;
            long long val = max(prev + 1, low);
            if (val <= high) {
                count++;
                prev = val;
            }
        }
        return count;
    }
};
