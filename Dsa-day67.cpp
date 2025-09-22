class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxFreq = 0, total = 0;
        for (int n : nums) {
            freq[n]++;
            if (freq[n] > maxFreq) maxFreq = freq[n];
        }
        for (int n : nums) {
            if (freq[n] == maxFreq) total++;
        }
        return total;
    }
};
