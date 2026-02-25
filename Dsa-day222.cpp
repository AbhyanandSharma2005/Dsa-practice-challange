class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int Ca = __builtin_popcount(a);
            int Cb = __builtin_popcount(b);

            if(Ca == Cb)
                return a < b;
            return Ca < Cb;
        });

        return arr;
    }
};