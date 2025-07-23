class Solution {
public:
    string remaining;

    int removePattern(const string& s, char first, char second, int value) {
        string temp;
        int score = 0;

        for (char c : s) {
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back();  
                score += value;   
            } else {
                temp.push_back(c);
            }
        }

        remaining = temp;
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        if (x > y) {
            totalScore += removePattern(s, 'a', 'b', x);
            totalScore += removePattern(remaining, 'b', 'a', y);
        } else {
            totalScore += removePattern(s, 'b', 'a', y);
            totalScore += removePattern(remaining, 'a', 'b', x);
        }

        return totalScore;
    }
};
