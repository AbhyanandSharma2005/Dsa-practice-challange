class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        vector<int> L(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                L[i] = L[i - 1] + 1;
            }
        }

        auto canFind = [&](int k) -> bool {
            if (2 * k > n) {
                return false;
            }
            
            for (int a = 0; a <= n - 2 * k; ++a) {
                int end1 = a + k - 1;
                int end2 = a + 2 * k - 1;
                
                if (L[end1] >= k && L[end2] >= k) {
                    return true;
                }
            }
            
            return false;
        };

        int low = 1;
        int high = n / 2;
        int max_k = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canFind(mid)) {
                max_k = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
                
        return max_k;
    }
};