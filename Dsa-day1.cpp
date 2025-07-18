class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        vector<long long> leftMins(size, 0);

        for (int i = 0; i < n; ++i) {
            leftSum += nums[i];
            maxHeap.push(nums[i]);
        }
        leftMins[n - 1] = leftSum;

        for (int i = n; i < 2 * n; ++i) {
            leftSum += nums[i];
            maxHeap.push(nums[i]);
            leftSum -= maxHeap.top();
            maxHeap.pop();
            leftMins[i] = leftSum;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        vector<long long> rightMaxs(size, 0);

        for (int i = size - 1; i >= size - n; --i) {
            rightSum += nums[i];
            minHeap.push(nums[i]);
        }
        rightMaxs[size - n] = rightSum;

        for (int i = size - n - 1; i >= n; --i) {
            rightSum += nums[i];
            minHeap.push(nums[i]);
            rightSum -= minHeap.top();
            minHeap.pop();
            rightMaxs[i] = rightSum;
        }

        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, leftMins[i] - rightMaxs[i + 1]);
        }

        return res;
    }
};
