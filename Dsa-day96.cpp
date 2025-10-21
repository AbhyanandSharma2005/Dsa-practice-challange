class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> counts(maxNum + k + 1, 0);
        for (int num : nums) counts[num]++;
        vector<int> pre(counts.size());
        pre[0] = counts[0];
        for (int i = 1; i < counts.size(); ++i)
            pre[i] = pre[i - 1] + counts[i];
        int res = 0;
        for (int i = 0; i + k < counts.size(); ++i) {
            int left = max(0, i - k - 1);
            int right = min(i + k, (int)pre.size() - 1);
            int mid = counts[i];
            int candidate = pre[right] - pre[left] - mid;
            res = max(res, mid + min(numOperations, candidate));
        }
        return res;
    }
};
