class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, odd = 0, ans = 0, even = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {

            if (nums[r] % 2 != 0)
                odd++;

            while (odd > k) {
                if (nums[l] % 2 != 0)
                    odd--;

                l++;
                even = 0;
            }

            if (odd == k) {
                while (l < r && nums[l] % 2 == 0) {
                    even++;
                    l++;
                }

                ans += even + 1;
            }
        }

        return ans;
    }
};