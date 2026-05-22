class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto found = find(nums.begin(), nums.end(), target);
        if(found == nums.end())
            return -1;
        else return found-nums.begin();
    }
};