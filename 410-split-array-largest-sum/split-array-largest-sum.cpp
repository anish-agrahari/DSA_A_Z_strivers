class Solution {
public:
    bool canSplit(vector<int>& nums, int n, int k, int maxSum) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxSum) {
                return false;
            }
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            } else {
                subarrayCount++;
                currentSum = nums[i];
            }
        }

        return subarrayCount <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int start = 0;
        int end = sum;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canSplit(nums, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};