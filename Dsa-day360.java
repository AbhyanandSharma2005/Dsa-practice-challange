class Solution {
    public String smallestPalindrome(String s) {
        int[] freq = new int[26];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        StringBuilder sb = new StringBuilder();
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            int f = freq[i];
            if (f == 0) continue;

            for (int j = 1; j <= f / 2; j++) {
                sb.append((char) (i + 'a'));
            }

            freq[i] -= f / 2;

            if (f % 2 == 1) {
                mid = (char) (i + 'a');
                freq[i]--;
            }
        }

        if (mid != '#') {
            sb.append(mid);
        }

        for (int i = 25; i >= 0; i--) {
            int f = freq[i];
            if (f == 0) continue;

            for (int j = 1; j <= f; j++) {
                sb.append((char) (i + 'a'));
            }
        }

        return sb.toString();
    }
}