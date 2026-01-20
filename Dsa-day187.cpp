class Solution {
public:
    int helper(int num) {
        if(num == 2) return -1; // 2 is the only prime number
        // Find the trailing 1's
        int temp = num;
        int count = 0;
        while(temp & 0x1) {
            ++count;
            temp >>= 1;
        }
        // return (num ^ (1 << count-1)); // this is also okay
        return (num & (~(1 << count-1)));
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> vec;
        for(int num : nums) {
            int x = helper(num);
            vec.push_back(x);
        }
        return vec;
    }
};