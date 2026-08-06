class Solution {
public:
    int digitP(int x) {
        int p=1;
        while(x>0) {
            int d=x%10;
            x/=10;
            p*=d;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++) {
            int p=digitP(i);
            if(p%t==0)
                return i;
        }
        return 0;
    }
};