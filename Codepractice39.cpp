class Solution {
public:
    int minOperations(string s) {
        int minCharIdx=0;
        char minChar=s[0];
        int maxCharIdx=0;
        char maxChar=s[0];
        int n=s.size();
        if(n==1) return 0;
        for(int i=1;i<n;i++){
            if(s[i] < minChar){
                minChar=s[i];
                minCharIdx=i;
            }

            if(s[i] >= maxChar){
                maxChar=s[i];
                maxCharIdx=i;
            }


        }

        if(minCharIdx==n-1){
            if(n==2) return -1;
            else if(maxCharIdx==0) return 3;
            else return 2;
        }

        else if(minCharIdx==0) {
            string temp=s;
            sort(temp.begin(),temp.end());
            if(temp==s) return 0;
            else return 1;

        }

        else {
            if(maxCharIdx==n-1) return 1;
            else return 2;
        }

    }
}