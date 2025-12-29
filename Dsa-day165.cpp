class Solution {
public:
    unordered_map<string, vector<char>> trans;
    unordered_set<string> fail;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& s : allowed) {
            string key = s.substr(0, 2);
            trans[key].push_back(s[2]);
        }
        return dfs(bottom);
    }

private:
    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (fail.count(row)) return false;

        vector<string> nextRows;
        string curr;
        buildNextRows(row, 0, curr, nextRows);

        for (const string& next : nextRows) {
            if (dfs(next)) return true;
        }

        fail.insert(row);
        return false;
    }

    void buildNextRows(const string& row, int idx, string& curr, vector<string>& res) {
        if (idx == row.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = row.substr(idx, 2);
        auto it = trans.find(key);
        if (it == trans.end()) return;

        for (char c : it->second) {
            curr.push_back(c);
            buildNextRows(row, idx + 1, curr, res);
            curr.pop_back();
        }
    }
};