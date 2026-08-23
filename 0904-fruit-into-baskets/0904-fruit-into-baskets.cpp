class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int max_len = 0;
        int k = 2;

        unordered_map<int, int> mp;

        while (r < n) {
            mp[nums[r]]++;

            if (mp.size() > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                l++;
            }

            if (mp.size() <= k) {
                max_len = max(max_len, r - l + 1);
            }

            r++;
        }

        return max_len;
    }
};