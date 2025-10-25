class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7, days = n % 7;
        int total = 28 * weeks + 7 * (weeks * (weeks - 1)) / 2;
        total += days * (2 * weeks + days + 1) / 2;
        return total;
    }
};
