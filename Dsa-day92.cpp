class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<tuple<int,int,set<char>>> prefix(n), suffix(n);

        int partitions = 0, lastStart = 0;
        set<char> chars;
        for (int i = 0; i < n; ++i) {
            prefix[i] = {partitions, lastStart, chars};
            chars.insert(s[i]);
            if ((int)chars.size() > k) {
                partitions++;
                lastStart = i;
                chars = {s[i]};
            }
        }

        partitions = 0;
        lastStart = n - 1;
        chars.clear();
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = {partitions, lastStart, chars};
            chars.insert(s[i]);
            if ((int)chars.size() > k) {
                partitions++;
                lastStart = i;
                chars = {s[i]};
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            set<char> merged = get<2>(prefix[i]);
            merged.insert(get<2>(suffix[i]).begin(), get<2>(suffix[i]).end());
            int contribution = 0;
            if ((int)merged.size() < k || k >= 26)
                contribution = 1;
            else if ((int)get<2>(prefix[i]).size() == k &&
                     (int)get<2>(suffix[i]).size() == k &&
                     (int)merged.size() < 26)
                contribution = 3;
            else
                contribution = 2;
            ans = max(ans, get<0>(prefix[i]) + get<0>(suffix[i]) + contribution);
        }
        return ans;
    }
};
