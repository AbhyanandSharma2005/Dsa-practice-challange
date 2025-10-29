class Solution {
    public int smallestNumber(int n) {
        int bits = 0;
        while ((1 << bits) - 1 < n) bits++;
        return (1 << bits) - 1;
    }
}
