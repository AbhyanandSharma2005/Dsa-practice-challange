class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false);
        for (int num : nums) {
            present[num] = true;
        }
        int target = k;
        while (target <= 100 && present[target]) {
            target += k;
        }
        return target;
    }
};