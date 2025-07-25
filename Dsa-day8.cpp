class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique;
        int sum = 0;
        for (int num : nums) {
            if (num > 0) {
                unique.insert(num);
            }
        }
        for (int val : unique) {
            sum += val;
        }
        if (sum == 0) {
            return *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};
