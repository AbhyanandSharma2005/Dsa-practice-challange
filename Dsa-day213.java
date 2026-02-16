class Solution {
    public int reverseBits(int n) {
        String s1 = String.format("%32s",Integer.toBinaryString(n)).replace(' ','0');
        String s2 = new StringBuilder(s1).reverse().toString();
        int res = (int) Long.parseLong(s2,2);
        return res;
    }
}