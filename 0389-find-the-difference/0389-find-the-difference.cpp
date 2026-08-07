class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss[256] = {0};
        int tt[256] = {0};
        char ans='\0';
       
        for(int i=0;i<t.size();i++){
            if(i<s.size()) ss[s[i]]++;
            tt[t[i]]++;
        }
        for(int i=0;i<256;i++){
            if(tt[i]!=ss[i]) ans = (char)i;
        }
        
        return ans;
    }
};