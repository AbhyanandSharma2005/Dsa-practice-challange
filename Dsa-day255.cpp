class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> a(26,0), b(26,0);
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(i%2){
                a[s1[i]-'a']++;
                b[s2[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
            a[i]=b[i]=0;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                a[s1[i]-'a']++;
                b[s2[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
            a[i]=b[i]=0;
        }
        return true;
    }
};