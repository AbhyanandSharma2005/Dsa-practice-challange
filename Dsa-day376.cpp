class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo = 0, n = nums.size(), zz = 0;
        for(auto i : nums) {
            if(i == 0) zz++;
            xo ^= i;
        }
        if(xo) return n;
        else if(zz == n) return 0;
        else return n-1;
    }
};