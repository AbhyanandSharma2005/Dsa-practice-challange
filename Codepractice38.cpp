class Solution {
public:
    bool isValid(vector<int>& nums, vector<int>& sortedArray, int k)
    {
        int n = nums.size();

        for (int i = 0; i < n; i += k)
        {
            vector<int> v1(nums.begin() + i, nums.begin() + i + k);
            vector<int> v2(sortedArray.begin() + i,
                           sortedArray.begin() + i + k);

            vector<int> doubled = v1;
            doubled.insert(doubled.end(), v1.begin(), v1.end());

            bool found = false;

            for (int j = 0; j < k; j++)
            {
                if (equal(v2.begin(), v2.end(),
                          doubled.begin() + j))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums)
    {
        int n = nums.size();
        int result = 0;

        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());

        for (int k = 1; k <= n; k++)
        {
            if (n % k == 0)
            {
                if (isValid(nums, sortedArray, k))
                {
                    result += k;
                }
            }
        }

        return result;
    }
};