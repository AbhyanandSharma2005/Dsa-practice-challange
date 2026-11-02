class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[size / 2];
        int count = 0;

        for(int i = 0; i < size; i++) {
            count += abs(median - nums[i]);
        }

        return count;
    }
};