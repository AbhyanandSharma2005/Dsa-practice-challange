class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int ans = 0 ; 
        sort(nums.begin(),nums.end());
        if(n==1) return 0;
        if(n==2) return nums[1]-nums[0];
        
        for(int i=n-1;i>0;i--)
        {
            ans+=(nums[i]-nums[0]);
        }
        //if((nums[1]-nums[0] != 1) && (nums[0]%2 != nums[1]%2)) ans++;

        return ans; 
    }
};