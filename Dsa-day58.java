class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        String vowels = "aeiou";
        int maxVowel = 0, maxCons = 0;
        for (int i = 0; i < 26; i++) {
            char c = (char)(i + 'a');
            if (vowels.indexOf(c) != -1) maxVowel = Math.max(maxVowel, freq[i]);
            else maxCons = Math.max(maxCons, freq[i]);
        }
        return maxVowel + maxCons;
    }
}
