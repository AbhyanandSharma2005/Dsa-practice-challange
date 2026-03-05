class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string s1="";
        string s2="";
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(i%2==0) {
                s1+="1";
                s2+="0";
            }
            else {
                s1+="0";
                s2+="1";
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]) cnt1++;
            if(s[i]!=s2[i]) cnt2++;
        }
            
        return min(cnt1,cnt2);
    }
};