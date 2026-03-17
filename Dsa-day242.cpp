class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m, vector<int> (n, 0));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == 0){
                    if(matrix[i][j] == 1)
                        prefix[i][j] = 1;
                }
                else{
                    if(matrix[i][j] == 1)
                        prefix[i][j] = prefix[i-1][j] + 1;
                    else
                        prefix[i][j] = 0;    
                }    
            }
        }
        
        int maxi = 0;
        for(int i=0 ; i<m ; i++){
            vector<int> temp;
            for(int j=0 ; j<n ; j++){
                if(prefix[i][j] != 0)
                    temp.push_back(prefix[i][j]);
            }

            sort(temp.begin(), temp.end());
            int k = temp.size();
            for(int i=0 ; i<k ; i++){
                maxi = max(maxi, temp[i] * (k-i));
            }
        }  
        return maxi; 
    }
};