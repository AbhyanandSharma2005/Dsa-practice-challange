class Solution {
public:
    long long sumAndMultiply(int n) {
        string str{to_string(n)}, tmp{};
        int sum = 0;
        for(char ch : str)
            if(ch != '0')
            {
                tmp += ch;
                sum += ch - '0';
            }
        if(sum == 0)
            return 0;
        int num = stoi(tmp);
        return (long long) num*sum;
    }
};