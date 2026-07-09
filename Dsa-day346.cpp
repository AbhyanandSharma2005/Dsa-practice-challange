class DSU{
    vector<int> parent, sizes;
    public:
    DSU(int n){
        parent.resize(n);
        for(int i = 1;i < n;i++)
            parent[i] = i;
        sizes.resize(n, 1);
    }

    int findParent(int n){
        if(parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void unite(int u, int v){
        int ultu = findParent(u);
        int ultv = findParent(v);

        if(ultu == ultv) return;

        if(sizes[ultu] < sizes[ultv]){
            parent[ultu] = ultv;
            sizes[ultv] += sizes[ultu];
        }
        else{
            parent[ultv] = ultu;
            sizes[ultu] += sizes[ultv];
        }
    }

    bool areUnited(int u, int v){
        return findParent(u) == findParent(v);
    }
};


class Solution {
public:
    int ub(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] <= target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return high;
    }

    int lb(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i = 0;i < n;){
            int s = lb(nums, nums[i] - maxDiff);
            int e = ub(nums, nums[i] + maxDiff);
            for(int j = s;j <= e;j++){
                dsu.unite(i, j);
            }
            i = e + 1;
        }
        vector<bool> res;
        for(vector<int> &q: queries){
            int u = q[0], v = q[1];
            res.push_back(dsu.areUnited(u, v));
        }
        return res;
    }
};