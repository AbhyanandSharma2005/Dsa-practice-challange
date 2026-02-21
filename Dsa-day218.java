class Solution {
    public int countPrimeSetBits(int left, int right) {
        int count = 0;
        int primes = 0b10100010100010101100;
        for (int i = left; i <= right; i++) {
            if (((primes >> Integer.bitCount(i)) & 1) == 1) count++;
        }
        return count;
    }
}