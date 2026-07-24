class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }
        int bits = 1;
        while ((1 << bits) <= maxVal) {
            bits++;
        }
        int limit = 1 << bits;

        vector<bool> present(limit, false);
        for (int x : nums) {
            present[x] = true;
        }

        vector<int> uniqueVals;
        for (int v = 0; v < limit; v++) {
            if (present[v]) {
                uniqueVals.push_back(v);
            }
        }

        vector<bool> pairXor(limit, false);
        int uCount = uniqueVals.size();
        for (int i = 0; i < uCount; i++) {
            for (int j = i; j < uCount; j++) {
                pairXor[uniqueVals[i] ^ uniqueVals[j]] = true;
            }
        }

        vector<bool> tripleXor(limit, false);
        for (int p = 0; p < limit; p++) {
            if (pairXor[p]) {
                for (int i = 0; i < uCount; i++) {
                    tripleXor[p ^ uniqueVals[i]] = true;
                }
            }
        }

        int count = 0;
        for (int v = 0; v < limit; v++) {
            if (tripleXor[v]) {
                count++;
            }
        }
        return count;
    }
};