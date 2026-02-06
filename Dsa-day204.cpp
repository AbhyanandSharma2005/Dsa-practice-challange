class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxKeep = 1;
        int right = 0;
        
        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= (long long)nums[left] * k) {
                right++;
            }
            maxKeep = max(maxKeep, right - left);
        }
        
        return n - maxKeep;
    }
};