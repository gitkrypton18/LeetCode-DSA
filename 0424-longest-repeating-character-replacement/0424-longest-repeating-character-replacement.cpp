class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int max_len = 0;
        int maxFreq = 0;

        int freq[26] = {0};

        while (r < s.size()) {
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            max_len = max(max_len, r - l + 1);

            r++;
        }

        return max_len;
    }
};