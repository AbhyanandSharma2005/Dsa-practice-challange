class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int minn=INT_MAX;
        if(n<3){
            return -1;
        }
        int maxx=*max_element(nums.begin(),nums.end());
        vector<int> v(maxx+1,0);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(v[nums[i]]>=3){
                int b=-1;
                int c=-1;
                for(int j=i+1;j<n;j++){
                    if(nums[i]==nums[j] &&b==-1){
                        b=j;
                    }
                    else if(nums[i]==nums[j] && c==-1){
                        c=j;
                        break;
                    }
                }
                
                minn=min(minn,abs(i - b) + abs(b - c) + abs(c - i));
               v[nums[i]]--; 

            }
        }
        if(minn==INT_MAX){
            return -1;
        }
        return minn;
    }
};