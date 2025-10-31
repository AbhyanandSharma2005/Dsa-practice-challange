class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(int x: nums){
            freq[x]++;
            if(freq[x]==2) res.push_back(x);
        }
        return res;
    }
};
