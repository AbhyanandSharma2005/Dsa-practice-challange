class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& op : operations) {
            if (op.find('+') != string::npos) x++;
            else x--;
        }
        return x;
    }
};
