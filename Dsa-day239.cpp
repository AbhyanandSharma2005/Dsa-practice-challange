class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int count = 0;
        function<bool(string&)> dfs = [&](string &cur) -> bool {
            if (cur.size() == n) { 
                count++;
                if (count == k) {  
                    ans = cur;
                    return true;
                }
                return false;
            }
            for (char c : {'a', 'b', 'c'}) {
                if (cur.empty() || cur.back() != c) { 
                    cur.push_back(c);
                    if (dfs(cur)) return true;
                    cur.pop_back();  
                }
            }
            return false;
        };
        
        string cur;
        dfs(cur);
        return ans;
    }
};
