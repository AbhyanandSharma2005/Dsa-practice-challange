class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0;
        int mx=INT_MIN;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[left]]--;
                left++;
            }
            mx=max(mx,i-left+1);
        }
        return mx;
    }
};