class Solution {
    public boolean hasAllCodes(String s, int k) {
        int total = 1 << k;
        int n = s.length();
        if(n < k || n-k+1 < total) return false;
        Set<String> set = new HashSet<>();
        for(int i = 0; i <= s.length()-k; i++){
            set.add(s.substring(i, i+k));
            if(set.size() == total) return true;
        }
        return set.size() == total ? true : false;
    }
}