class Solution {
public:
    int mirrorDistance(int n) {
        int copy = 0;
        int num = n;
        while (n > 0) {
            copy = copy * 10 + n % 10;
            n /= 10;
        }
        if (num > copy) {
            return (num - copy);
        }
        return (copy - num);
    }
};