public class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for (int i = n - 1; i >= -1; --i) {
            int[] curCount = count.clone();
            boolean possible = true;
            for (int j = 0; j < i; ++j) {
                if (--curCount[target.charAt(j) - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

            int nextChar = -1;
            if (i >= 0) {
                for (int c = target.charAt(i) - 'a' + 1; c < 26; ++c) {
                    if (curCount[c] > 0) {
                        nextChar = c;
                        break;
                    }
                }
                if (nextChar == -1) continue;
            }

            StringBuilder res = new StringBuilder();
            for (int j = 0; j < i; ++j) {
                res.append(target.charAt(j));
            }
            if (i >= 0) {
                res.append((char) ('a' + nextChar));
                curCount[nextChar]--;
            }

            for (int c = 0; c < 26; ++c) {
                while (curCount[c] > 0) {
                    res.append((char) ('a' + c));
                    curCount[c]--;
                }
            }

            String ans = res.toString();
            if (i == -1) {
                if (ans.compareTo(target) > 0) return ans;
            } else {
                return ans;
            }
        }

        return "";
    }
}