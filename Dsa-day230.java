class Solution {
    public int minOperations(String s) {
       int c0 = 0;
       int c1 = 0;
       boolean flag = true;

       for(char ch : s.toCharArray()){
            if(flag && ch == '1') c0++;
            else if(!flag && ch == '0') c0++;

            if(flag && ch == '0') c1++;
            else if(!flag && ch == '1') c1++;

            flag = !flag;
       }

       return Math.min(c0, c1);
    }
}