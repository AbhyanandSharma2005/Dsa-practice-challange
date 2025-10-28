class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        auto simulate = [&](int start, int dir) {
            vector<int> arr = nums;
            int curr = start, n = arr.size();
            while (curr >= 0 && curr < n) {
                if (arr[curr] == 0) curr += dir;
                else {
                    arr[curr]--;
                    dir *= -1;
                    curr += dir;
                }
            }
            for (int x : arr) if (x != 0) return false;
            return true;
        };
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (simulate(i, 1)) res++;
                if (simulate(i, -1)) res++;
            }
        }
        return res;
    }
};
