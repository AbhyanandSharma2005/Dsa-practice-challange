class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string,int>mp;
        for(int i = 0; i < arr1.size(); i++){
            string s = to_string(arr1[i]);
            string prefix = "";
            for(auto ch : s){
                prefix.push_back(ch);
                mp[prefix] = prefix.size();
            }
        }
        
        for(int i = 0; i < arr2.size(); i++){
            string s = to_string(arr2[i]);
            string prefix = "";
            for(auto ch : s){
                prefix.push_back(ch);
                
                ans = max(ans,mp[prefix]);
            }
        }

        return ans;
    }
};