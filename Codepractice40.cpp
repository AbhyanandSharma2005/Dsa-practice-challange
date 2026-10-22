class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int cnt_asc = 0;
        int cnt_dsc = 0;

        for(int i = 1; i < n; i++) {
            cnt_asc += (nums[i] == (nums[i-1]+1)%n);
            cnt_dsc += (nums[i-1] == (nums[i]+1)%n);
        }

        // already sorted in asc order :) 0, 1, 2, 3, ...., n-1
        if(cnt_asc == n-1 && nums[0] == 0)    return 0;
        

        if(cnt_asc == n-1) {
            int left_rotation  = n - nums[0];
            int right_rotation = 1 + (nums.back() + 1) + 1;
            return min(left_rotation, right_rotation);
        }

        if(cnt_dsc == n-1) {
            //Mandatory 1 Reverse
            int left_rotation = n-nums.back() + 1;
            //xLeft Rotation + 1 Reverse
            int right_rotation = (nums[0] + 1) % n + 1;

            return min(left_rotation, right_rotation);
        }

        return -1;
    }
};