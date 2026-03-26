class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                res[j][n-i-1]=arr[i][j]; 
            }
        }
        return res;
    }
    bool canPartitionGrid(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        int m=arr[0].size();
        long long total=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                total+=arr[i][j];
            }
        }
        for(int k=0;k<4;k++)
        {
            unordered_set<long long> st;
            long long curr=0;
            n=arr.size();
            m=arr[0].size();
            int i,j;
            cout<<endl;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    curr+=arr[i][j];
                    st.insert(arr[i][j]);
                }
                if((2*curr)==total) return true; 
                long long x=(2*curr-total);
                if(i==0)
                {
                    if(x==arr[0][0] || x==arr[0][m-1]) 
                    {
                        return true;
                    }
                }
                else if(m==1)
                {
                    if(x==arr[0][0] || x==arr[i][0]) 
                    {
                        return true;
                    }
                }
                else if(st.find(x)!=st.end()) 
                {
                    cout<<total<<" "<<x<<" "<<curr<<" "<<i<<" "<<j<<endl;
                    return true;
                }
            }
            arr=rotate(arr);
        }
        return false;
    }
};
