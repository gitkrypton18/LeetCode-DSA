class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0;
        int sum = 0;
        int ans = 0;
        int zeroCount = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (l < r && sum > goal) {
                sum -= nums[l];
                l++;
                zeroCount = 0;
            }

            if (sum == goal) {
                while (l < r && nums[l] == 0) {
                    zeroCount++;
                    l++;
                }

                ans += zeroCount + 1;
            }
        }

        return ans;
    }
};