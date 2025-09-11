class Solution {
    public String sortVowels(String s) {
        String vowels = "aeiouAEIOU";
        StringBuilder v = new StringBuilder();
        for(char c:s.toCharArray()) if(vowels.indexOf(c)>=0) v.append(c);
        char[] arr = v.toString().toCharArray();
        java.util.Arrays.sort(arr);
        StringBuilder res = new StringBuilder();
        int j=0;
        for(char c:s.toCharArray()){
            if(vowels.indexOf(c)>=0) res.append(arr[j++]);
            else res.append(c);
        }
        return res.toString();
    }
}
