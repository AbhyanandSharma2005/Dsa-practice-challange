class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int oddCount = 0;
        int evenCount = 1;
        int currentSum = 0;
        int result = 0;
        
        for (int num : arr) {
            currentSum += num;
            if (currentSum % 2 != 0) {
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }
        
        return result;
    }
};
