class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        freq[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int num : nums) {
            sum += num;

            int required = sum - k;

            if (freq.count(required))
                ans += freq[required];

            freq[sum]++;
        }

        return ans;
    }
};