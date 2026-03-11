class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        if(((n+1) & n) == 0){
            return 0;
        }
        int r = 1;
        while(true){
            if(((1 << r) - 1) > n){
                break;
            }
            r++;
        }
        return (1 << r) - 1 - n;
    }
};