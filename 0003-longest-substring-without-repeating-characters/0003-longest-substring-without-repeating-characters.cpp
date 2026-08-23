class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n=s.size();
        int l=0,r=0,len=0,max_len=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()) {
                l=max(l, mp[s[r]] + 1);
            }
            
                mp[s[r]]=r;
                len=r-l+1;
                max_len=max(max_len,len);
            
            r++;
        } 
        return max_len;
    }
};