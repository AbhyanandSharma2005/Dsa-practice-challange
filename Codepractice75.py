class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> mc(nums[n - 1] + 2, 0);

        for(int i = 0; i < n; i++) {
            int minusOne = mc[nums[i] - 1];
            int zero = mc[nums[i]];
            mc[nums[i]] = 1 + minusOne;
            mc[nums[i] + 1] = 1 + zero;
        }

        return *max_element(mc.begin(), mc.end());
    }
};