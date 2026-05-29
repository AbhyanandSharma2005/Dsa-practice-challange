class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX, sum = 0;

        for(int n : nums) {
            sum = 0;
            while(n != 0) {
                sum += n % 10;
                n /= 10;
            }
            minSum = min(sum, minSum);
        }

        return minSum;
    }
};