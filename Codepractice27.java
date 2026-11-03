class Solution {
    public int minMoves(int[] nums) {
        int res=0;
        int max=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]>max){
                res+=i*(nums[i]-max);
                max=nums[i];
            }else{
                res+=max-nums[i];
            }
        }
        return res;
    }
}