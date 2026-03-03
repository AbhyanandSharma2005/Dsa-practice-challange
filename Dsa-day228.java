class Solution {
    public char findKthBit(int n, int k) {
        int mid = 0; 
        int count = 0; 

        while (k > 2) {

            int aux = (int)(Math.log(k) / Math.log(2));

            if ((1 << aux) == k && count == 0) return '1';

            if ((1 << aux) == k) {
                k = 2;
                break;
            } 
            else {
                mid = 1 << aux;
                k = mid - (k - mid); 
            }

            count++;
        }

        if ((k < 2 && count % 2 == 0) || (k >= 2 && count % 2 == 1))
            return '0';
        else
            return '1';
    }
}