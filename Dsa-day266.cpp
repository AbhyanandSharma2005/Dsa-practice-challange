class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         int n = nums.size();
         int mindis = INT_MAX;
        int ans =0;
         for(int i=0 ; i<n ; i++)
             {
                  for(int j= i+1 ; j<n ; j++)
                      {
                           for(int k= j+1 ; k<n ; k++)
                               { 
                                   if(nums[i]==nums[j] && nums[j]==nums[k])
                                   {
                                         ans = abs(i-j)+abs(j-k)+abs(k-i);
                                        mindis = min(mindis , ans);
                                   }
                               }  
                               
                              
                      } 
                 
             } 
         return (mindis ==INT_MAX)? -1 :mindis;
    }
};