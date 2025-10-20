class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(s);
        string ans = s;
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            if (seen.count(curr)) continue;
            seen.insert(curr);
            ans = min(ans, curr);
            string added = curr;
            for (int i = 1; i < added.size(); i += 2)
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (!seen.count(added)) q.push(added);
            if (!seen.count(rotated)) q.push(rotated);
        }
        return ans;
    }
};
