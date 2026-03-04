class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    //cout<<i<<" "<<j;
                    bool b= true;
                    for(int k=0; k<mat.size(); k++){
                        if(k!=i && mat[k][j]==0) continue;
                        if(k==i) continue;
                        else {
                            b=false;
                            break;
                        }
                    }
                    if(b){
                        for(int k=0; k<mat[0].size(); k++){
                        if(k!=j && mat[i][k]==0) continue;
                        if(k==j) continue;
                        else {
                            b=false;
                            break;
                        }
                    }
                    if(b) ans++;
                    }
                }
                
            }
        }
        return ans;
    }
};