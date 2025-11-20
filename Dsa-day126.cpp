class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? b[0] < a[0] : a[1] < b[1];
        });
        int ans = 0;
        int p1 = -1, p2 = -1;
        for (auto& iv : intervals) {
            int s = iv[0], r = iv[1];
            if (s > p2) {
                ans += 2;
                p1 = r - 1;
                p2 = r;
            } else if (s > p1) {
                ans++;
                p1 = p2;
                p2 = r;
            } else if (r < p2) {
                p1 = max(s, p1);
                p2 = r;
            }
        }
        return ans;
    }
};