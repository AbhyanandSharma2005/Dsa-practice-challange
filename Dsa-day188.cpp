class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            int number = nums[i];
            int count = 0;
            while (((number >> 1) & 1) == 1) {
                number = number >> 1;
                count++;
            }
            number = (1 << count);
            ans.push_back(nums[i]-number);
        }
        return ans;
    }
};