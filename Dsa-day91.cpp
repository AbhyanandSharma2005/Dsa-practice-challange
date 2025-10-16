class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[(x % value + value) % value]++;
        int i = 0;
        while (true) {
            int r = i % value;
            if (freq[r] == 0) return i;
            freq[r]--;
            i++;
        }
    }
};
