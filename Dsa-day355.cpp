class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        int power=0;
        while(k){
            k/=2;
            power++;
        }
        int ans=0;
        if(n>2){
            ans=pow(2,power);
        }
        else if(n==2){
            ans=2;
        }
        else{
            ans=1;
        }
        // cout<<power<<endl;
        return ans;
    }
};