class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int arrSum=0;
        for (int i : nums) arrSum+=i;

        int currSum = 0;
        for (int i=0; i<nums.size(); i++) currSum+=(i*nums[i]);

        int ans = currSum;        
        for (int i=nums.size()-1; i>=0; i--) {
            currSum = currSum+arrSum-(nums[i]*nums.size());
            ans = max(ans, currSum);
        }
        return ans;
    }
};