class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> last(32, -1);  

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    last[b] = i;
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) {
                    maxReach = max(maxReach, last[b]);
                }
            }

            res[i] = maxReach - i + 1;  
        }

        return res;
    }
};
