class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<bool> lowerSeen(26, false);

        vector<int> allChar(26, -1);

        int count = 0;

        for (char c : word) {

            if (islower(c)) {

                int idx = c - 'a';

                if (allChar[idx] == 0) {
                    allChar[idx] = 1;
                    count--;
                }

                lowerSeen[idx] = true;
            }

            else {

                int idx = c - 'A';

                if (lowerSeen[idx]) {

                    if (allChar[idx] == -1) {
                        allChar[idx] = 0;
                        count++;
                    }

                } else {

                    allChar[idx] = 1;
                }
            }
        }

        return count;
    }
};