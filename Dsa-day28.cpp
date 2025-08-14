class Solution {
public:
    string largestGoodInteger(string num) {
        string maxGood = "";
        
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            string sub = num.substr(i, 3);
            if (sub[0] == sub[1] && sub[1] == sub[2]) {
                if (maxGood == "" || sub > maxGood) {
                    maxGood = sub;
                }
            }
        }
        
        return maxGood;
    }
};
