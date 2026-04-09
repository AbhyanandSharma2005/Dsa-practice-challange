#include <math.h>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        // container for multipliers for different steps
        // multipliers are stored in SegmentTree to join the corresponding queries
        std::unordered_map<int, std::unordered_map<int, SegmentTree>> mps;

        // fill-in multipliers
        for (const auto& query: queries) {
            // create or get a container for multipliers with 'k' step 
            auto& mps_k{mps.try_emplace(query[2]).first->second};
            // create or get a SegmentTree of multipliers with 'k' step and shift
            int shift{query[0] % query[2]};
            size_t mps_k_len{(nums.size() - shift - 1) / query[2] + 1};
            auto& mps_k_s{mps_k.try_emplace(shift, mps_k_len).first->second};
            int start{query[0] / query[2]};
            int end{(query[1] - query[0]) / query[2] + start};
            mps_k_s.update(start, end, query[3]);
        }

        // multiply each value with multipliers for each 'k' step
        for (auto& [k, mps_k]: mps) {
            for (auto& [shift, mps_k_s]: mps_k) {
                auto& mp_vals{mps_k_s.get()};
                for (int i = 0; i < mp_vals.size(); ++i) {
                    int& num{nums[shift + i*k]};
                    num = static_cast<int>(static_cast<long long>(num) * mp_vals[i] % mod);
                }
            }
        }

        // calculate bit XOR
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }

private:
    static const long long mod{1'000'000'007};

    class SegmentTree {
    public:
        explicit SegmentTree(size_t n) {
            size_t h{static_cast<size_t>(std::ceil(std::log2(n))) + 1};
            int len{1};
            tree.resize(h, {});
            seg_lens.resize(h);
            for (size_t i = h; i > 0; --i) {
                seg_lens[i - 1] = len;
                len *= 2;
            }
            seg_lens[0] = n;
            for (size_t i = h; i > 0; --i) {
                tree[i - 1].resize(n, 1);
                n = (n + 1) / 2;
            }
        };
        void update(int l, int r, int val) {
            if (r - l == 0) {
                op(tree[tree.size() - 1][l], val);
                return;
            }
            updateImpl(l, r, val, 0, 0);
        }
        std::vector<int>& get() {
            for (size_t i = 0; i < tree.size() - 1; ++i) {
                auto& cur{tree[i]};
                auto& next{tree[i + 1]};
                for (size_t j = 0; j < cur.size(); ++j) {
                    op(next[2*j], cur[j]);
                    if (2*j + 1 < next.size()) {
                        op(next[2*j + 1], cur[j]);
                    }
                }
            }
            return tree.back();
        }
    private:
        std::vector<std::vector<int>> tree;
        std::vector<int> seg_lens;
        void updateImpl(int l, int r, int val, size_t level, int seg_idx) {
            if (level == tree.size() - 1) {
                op(tree[level][seg_idx], val);
                return;
            }
            int seg_l{seg_lens[level + 1]*2*seg_idx};
            int seg_m{seg_lens[level + 1]*(2*seg_idx + 1) - 1};
            int seg_r{std::min(seg_lens[level + 1]*2*(seg_idx + 1) - 1, seg_lens[0] - 1)};
            if (l == seg_l && r == seg_r) {
                op(tree[level][seg_idx], val);
            } else {
                if (l <= seg_m) {
                    updateImpl(l, std::min(r, seg_m), val, level + 1, 2*seg_idx);
                }
                if (r > seg_m) {
                    updateImpl(std::max(l, seg_m + 1), r, val, level + 1, 2*seg_idx + 1);
                }
            }
        }
        void op(int& val, int mp) {
            val = static_cast<int>(static_cast<long long>(val) * static_cast<long long>(mp) % mod);
        }
    };
};