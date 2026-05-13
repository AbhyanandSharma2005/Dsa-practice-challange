class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2 * limit + 2, 0);
        
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            
            delta[2] += 2;
            delta[min(a, b) + 1] -= 1;
            delta[a + b] -= 1;
            delta[a + b + 1] += 1;
            delta[max(a, b) + limit + 1] += 1;
        }
        
        int moves = 0, minMoves = n;
        
        for (int target = 2; target <= 2 * limit; target++) {
            moves += delta[target];
            minMoves = min(minMoves, moves);
        }
        
        return minMoves;
    }
};