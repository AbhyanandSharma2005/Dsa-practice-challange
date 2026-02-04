class SegmentTree {
    int n;
    vector<long long> segMin, segMax;
    static constexpr long long INF = 1000000000000000000LL;

public:
    SegmentTree(vector<long long>& v) {
        n = v.size();
        segMin.resize(4 * n);
        segMax.resize(4 * n);
        build(1, 0, n - 1, v);
    }

    long long getMin(int l, int r) {
        return queryMin(1, 0, n - 1, l, r);
    }

    long long getMax(int l, int r) {
        return queryMax(1, 0, n - 1, l, r);
    }

private:
    void build(int idx, int l, int r, vector<long long>& v) {
        if (l == r) {
            segMin[idx] = segMax[idx] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid, v);
        build(2 * idx + 1, mid + 1, r, v);

        segMin[idx] = min(segMin[2 * idx], segMin[2 * idx + 1]);
        segMax[idx] = max(segMax[2 * idx], segMax[2 * idx + 1]);
    }

    long long queryMin(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return INF;

        if (ql <= l && r <= qr)
            return segMin[idx];

        int mid = (l + r) / 2;
        return min(
            queryMin(2 * idx, l, mid, ql, qr),
            queryMin(2 * idx + 1, mid + 1, r, ql, qr)
        );
    }

    long long queryMax(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return -INF;

        if (ql <= l && r <= qr)
            return segMax[idx];

        int mid = (l + r) / 2;
        return max(
            queryMax(2 * idx, l, mid, ql, qr),
            queryMax(2 * idx + 1, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
private:
    vector<vector<pair<int, int>>> getIncDec(vector<int> &nums) {
        int bit = 0;
        int prev = nums[0];
        int last = -1;
        vector<pair<int, int>> inc, dec;
        for (int i = 1; i < nums.size(); i++) {
            if (bit == 1) {
                if (nums[i] > prev) {
                    if (i == nums.size() - 1) {
                        inc.push_back({last, i});
                    }
                }
                else if(nums[i] < prev) {
                    inc.push_back({last, i - 1});
                    if (i == nums.size() - 1) {
                        dec.push_back({i - 1, i});
                    }
                    bit = -1;
                    last = i - 1;
                }
                else {
                    
                    inc.push_back({last, i - 1});
                    bit = 0;
                }
            }
            else if(bit == -1) {
                if (nums[i] < prev) {
                    if (i == nums.size() - 1) {
                        
                        dec.push_back({last, i});
                    }
                }
                else if(nums[i] > prev) {
                    
                    dec.push_back({last, i - 1});
                    if (i == nums.size() - 1) {
                        inc.push_back({i - 1, i});
                    }
                    bit = 1;
                    last = i - 1;

                }
                else {
                    
                    dec.push_back({last, i - 1});
                    bit = 0;
                }
            }
            else {
                if (nums[i] > prev) {
                    bit = 1;
                }
                else if(nums[i] < prev) {
                    bit = -1;
                }
                last = i - 1;
            }
            prev = nums[i];
        }
        return {inc, dec};
    }
    vector<long long> getPre(vector<int> &nums) {
        vector<long long> pre(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            pre[i] = pre[i - 1] + 1LL * nums[i - 1];
        }
        return pre;
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        vector<vector<pair<int, int>>> incdec = getIncDec(nums);
        vector<pair<int, int>> inc = incdec[0];
        vector<pair<int, int>> dec = incdec[1];
        vector<long long> pre = getPre(nums);
        SegmentTree st(pre);
        long long ans = -1e16;
        for (auto p: dec) {
            auto it = lower_bound(inc.begin(), inc.end(),make_pair(INT_MIN, p.first),[](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
        });
        if (it == inc.end() or it->second != p.first) {continue;}
        long long minny = st.getMin(it->first, it->second - 1);
        it = lower_bound(inc.begin(), inc.end(),make_pair(p.second, INT_MIN),[](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
        });
        if (it == inc.end() or it->first != p.second) {continue;}
        long long maxy = st.getMax(it->first + 2, it->second + 1);
        ans = max(maxy - minny, ans);
        }
        return ans;
    }
};