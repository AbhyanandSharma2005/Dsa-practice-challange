import java.util.List;

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int[] L = new int[n];
        L[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums.get(i) > nums.get(i - 1)) {
                L[i] = L[i - 1] + 1;
            } else {
                L[i] = 1;
            }
        }

        boolean canFind(int k, int[] L_arr, int n_arr) {
            if (2 * k > n_arr) {
                return false;
            }
            
            for (int a = 0; a <= n_arr - 2 * k; ++a) {
                int end1 = a + k - 1;
                int end2 = a + 2 * k - 1;
                
                if (L_arr[end1] >= k && L_arr[end2] >= k) {
                    return true;
                }
            }
            
            return false;
        }

        int low = 1;
        int high = n / 2;
        int max_k = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canFind(mid, L, n)) {
                max_k = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
                
        return max_k;
    }
}