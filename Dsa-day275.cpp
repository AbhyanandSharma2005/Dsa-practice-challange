class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;

        for(int i=0 ; i<nums1.size() ; i++){
            int fin = nums1[i];
            int hi = i;
            int lo = nums2.size()-1;
            while(hi<= lo){
                int mid = hi + (lo-hi)/2;
                if(nums2[mid]>=fin ){
                    ans = max(ans , mid-i);
                    hi = mid+1;
                }
                else lo = mid-1;
            }


        }

        return ans;
        
    }
};