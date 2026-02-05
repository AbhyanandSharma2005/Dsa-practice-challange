class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length; 
        int []result = new int[nums.length];
        for(int i=0; i<n;i++){
            if(nums[i] == 0){
                result[i] = nums[i];
            }else{
                int newIdx = (nums[i] + i)%n;
                if(newIdx < 0){
                    newIdx += n;
                }
                result[i] = nums[newIdx];
            }
        }
        return result;
    }
}