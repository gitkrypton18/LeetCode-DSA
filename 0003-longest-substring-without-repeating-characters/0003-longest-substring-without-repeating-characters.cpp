class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int n = s.size();
        int max_len=0,len=0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                freq[(unsigned char)s[j]]++;
                if ((freq[(unsigned char)s[j]]) > 1) {
                    break;
                }
                len=(j-i+1);
                max_len=max(max_len,len);


            }
            for (int k = 0; k < 256; k++) {
    freq[k] = 0;
}
        }
        return max_len;
    }
};