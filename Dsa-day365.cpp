class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(n,-1));

        // base case 
        for(int i =0 ;i<n;i++){
            dp[i][i] = nums[i];
        }

        // tabluation 

        for( int len = 2 ;len <=n;len++){
            for( int i = 0 ;len+i-1<n;i++){
                int j = len+i-1;

                int left = nums[i] - dp[i+1][j];

                int right = nums[j] - dp[i][j-1];

                dp[i][j] = max(left,right);
            }
        }

        return dp[0][n-1] >= 0;
    }
};

