class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int i=0;i<grid.size();i++){
            int total=0;
            for(int j=grid[i].size()-1;j>=0;j--){
                if(grid[i][j]==0){
                    total++;
                }else{
                    break;
                }
            }
            ans.push_back(total);
        }
        int val=grid[0].size()-1;
        int total=0;
        int temp=0;
        for(int i=0;i<ans.size()-1;i++){
            int flag=1;
            for(int j=i;j<ans.size();j++){
                if(ans[j]>=val-temp){
                    int tempj=j;
                    flag=0;
                    while(tempj>i){
                        swap(ans[tempj],ans[tempj-1]);
                        total++;
                        tempj--;
                    }
                    break;
                }
            }
            if(flag){
                return -1;
            }
            temp++;
        }
        
        return total;
    }
};