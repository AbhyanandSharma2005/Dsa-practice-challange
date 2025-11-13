class Solution {
    public int maxOperations(String s) {
        int count=0;
        int oneC=0;
        for(int i=0;i<s.length()-1;i++){
            if(s.charAt(i)=='1') oneC++;
            if(s.charAt(i)=='1' && s.charAt(i+1)=='0') count+=oneC;
        }
        return count;
    }
}