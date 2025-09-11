class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        auto isVowel = [&](char c){return vowels.find(c)!=string::npos;};
        string v;
        for(char c:s) if(isVowel(c)) v.push_back(c);
        sort(v.begin(), v.end());
        string res;
        int j=0;
        for(char c:s){
            if(isVowel(c)) res.push_back(v[j++]);
            else res.push_back(c);
        }
        return res;
    }
};
